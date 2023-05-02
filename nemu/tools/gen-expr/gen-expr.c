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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`

static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

int len = 0;	//buf use lenth
char *tmp;	//temporary arrty of buf
static uint64_t choose(uint64_t n){
	uint64_t i = rand() % n;
	return i;
}

static void gen_space(int n){
	char *space[3] = {
		" ",
		"  ",
		"   ",
	};
	sprintf(&tmp[len],"%s",*space);
	len++;
}

static void gen_num(){
	int num = choose(10);
	sprintf(&tmp[len],"%d",num);
	len++;
}

static void gen(char c){
	//buf[len] = c;
	sprintf(&tmp[len],"%c",c);
	len++;
}

static void gen_rand_op(){
	char rand_op[] = {'+','-','*','/','+','-','*'};
	//buf[len] = rand_op[choose(7)];
	sprintf(&tmp[len],"%c",rand_op[choose(7)]);
	len++;
}

static void gen_rand_expr() {
	int case_num = choose(3);
	if(len >= 16) case_num = 0;
	switch(case_num){ 
		case 0: gen_num();break;
		case 1: gen('(');gen_rand_expr();gen(')');break;
		case 2: gen_space(choose(3));
		default: gen_rand_expr();gen_rand_op();gen_rand_expr();break;	
	}
}


int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
	int i;
  for (i = 0; i < loop; i ++) {
		len = 0;
		tmp = buf;
    gen_rand_expr();
    sprintf(code_buf, code_format, buf);	//let the data of "code_format" and "buf" store in the code_buf
    
		FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);	//let code_buf store in *fp
		fclose(fp);
    
		int ret = system("gcc -Werror /tmp/.code.c -o /tmp/.expr");	//calcuting expressions
    if (ret != 0) continue;
    
		fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    fscanf(fp, "%d", &result);
		//if(result < 0) continue;
    pclose(fp);
		//if (ret != 0) continue; 
    printf("%u %s\n", result, buf);
  }
  return 0;
}
