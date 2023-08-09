/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ,
	TK_OR,TK_AND,TK_NEQ,TK_DEC,TK_HEX,TK_DEREF,TK_MINUS,TK_REG,	
  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"==", TK_EQ},        // equal
	{"\\-", '-'},					// subtract
  {"\\*", '*'},					// multiply
  {"\\/", '/'},					// divide
  {"\\(", '('},					// left parenthesis
  {"\\)", ')'},					// right parenthesis	
  {"[0-9]{1,10}", TK_DEC},							// decimal
  {"0x[0-9a-fA-F]{1,16}", TK_HEX},		// hexadecima
	{"\\$[a-zA-z]+[0-9]*",TK_REG},  	// reg																		
	{"%",'%'}, 
	{"!=", TK_NEQ},
	{"&&", TK_AND},
	{"\\|\\|", TK_OR},
	{"!",'!'},
};

#define NR_REGEX ARRLEN(rules)
static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i  < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  //char str[32];
	char str[1024+128];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
					case TK_NOTYPE:break;
					case TK_DEC:
					case TK_HEX:sprintf(tokens[nr_token].str,"%.*s",substr_len,substr_start);
					default: tokens[nr_token].type = rules[i].token_type;
									 nr_token++;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

static int op_prec(int t){
	switch(t){ 
		case '!':case TK_DEREF:return 0;
		case '*':case '?':case'%':return 1;
		case '+':case '-':return 2;
	  case TK_EQ:case TK_NEQ: return 4;
		case TK_AND: return 8;
		case TK_OR: return 9;
		default: assert(0);
	}
}

static inline int op_prec_cmp(int t1,int t2){
	return op_prec(t1) - op_prec(t2);
}

static int find_dominated_op(int s,int e,bool *success){
	int i;
	int bracket_level = 0;
	int dominated_op = -1;
	for(i = s ; i <=  e ; i++){
		switch(tokens[i].type)
		{ 
			case TK_DEC: case TK_HEX: break;
			
			case'(': 
					bracket_level --;
					if(bracket_level < 0){
						*success = false;
						return 0;
					}
					break;
			default:
				if(bracket_level == 0){
					if(dominated_op == -1 || op_prec_cmp(tokens[dominated_op].type,tokens[i].type ) <0 || (op_prec_cmp(tokens[dominated_op].type,tokens[i].type) == 0 && tokens[i].type != '!' && tokens[i].type != TK_DEREF)){
						dominated_op = i;
					}
				}
				break;
		}	
	}
	*success = (dominated_op != -1);

	return dominated_op;
}

static word_t eval(int p,int q,bool *success) {
	if(p > q ) {   
		success = false;
		//assert(0);
		return 0;
	}
	else if (p == q ) {
		//single token
		uint64_t val;
		 switch(tokens[p].type){
			case TK_DEC:
					val = strtoul(tokens[p].str,NULL,0);
					break;
			case TK_HEX:
					val = strtoul(tokens[p].str,NULL,0);
					break;
			default:assert(0);
		}
		*success = true;
		return val;
	}
	else if (tokens[p].type == '(' && tokens[q].type == ')'){
		return eval(p+1,q-1,success);
	}
 	else {   
		int dominated_op = find_dominated_op(p,q,success);
		if(!*success){return 0;}
		
		int op_type = tokens[dominated_op].type;
		if(op_type == '!' ) {
			uint64_t val = eval(dominated_op +1,q,success);
			if(!*success){return 0;}

			switch  (op_type){ 
				case'!':return !val;
				default:assert(0);
			}

		}
		
		uint64_t val1 = eval(p,dominated_op-1,success);
		uint64_t val2 = eval(dominated_op+1,q,success);
		
		if(!*success){return 0;}
		switch (op_type) {
			case '+':return val1+val2 ; 
			case '-':return val1-val2 ; 
			case '*':return val1*val2 ; 
			case '/':return val1/val2 ; 
			case TK_OR:return val1 || val2;
			case TK_AND:return val1 && val2;
			case TK_EQ:return val1 == val2;
			case TK_NEQ:return val1 != val2;
			default: assert(0);
		}
	}
}



word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
	int i;
	for (i = 0; i < nr_token; i ++){
		 if(tokens[i].type == '*' && (i == 0 || tokens[i-1].type != TK_DEC ||tokens[i-1].type != TK_HEX || tokens[i-1].type != ')' )){
			tokens[i].type = TK_DEREF;	//Pointer;
		}
	}
	return eval(0,nr_token-1,success);
  /* TODO: Insert codes to evaluate the expression. */
  TODO();

  return 0;
}
