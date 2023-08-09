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
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/vaddr.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
word_t expr();
void list_watchpoint();
bool delete_watchpoint(int no);
void scan_watchpoint(vaddr_t pc);
int set_watchpoint(char *e);
int test_expr();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if  (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  return -1;
}

static int cmd_si(char *args) {
	char *arg = strtok(NULL, " ");
	int step;
	if(args == NULL) step = 1;
	else sscanf(arg,"%d",&step);
  cpu_exec(step);
	return 0;
}

static int cmd_info(char *args) {
	char *arg = strtok(NULL," ");
	if(arg == NULL)
		return 0;
	else if(strcmp(arg,"r") == 0)
		isa_reg_display();
	else if(strcmp(arg,"w") == 0)
    list_watchpoint();
    //printf("info w haven't write");
	else {  
		printf("You should write info f/w");
	}
	return 0;
}

static int cmd_x(char *args){
	if (args == NULL) {
        printf("Wrong Command!\n");
        return 0;
    }
	int len,addr,i;
	sscanf(args,"%d %x",&len,&addr);
	for(i= 0;i<len;i++ ) {
		printf("0x%ox\t0x%0lx\n",addr,vaddr_read(addr,4));
		addr+=4;
	}

	return 0;
}

static int cmd_p(char *args){
	if(args != NULL){ 
		bool success;
		word_t p_temp=expr(args,&success);
		if(success){  
			printf("%lu\n",p_temp);
		}
		else {printf("Bad expression\n");}
	}
	return 0;
}

static int cmd_w(char *args){
  if(args == NULL){
    Log("Press the w $pc = ADDR/n ");
  }
  else{ 
    printf("Begin set\n");
    int no = set_watchpoint(args);
    printf("success set watchpoint\n");
    if(no != -1){
      printf("Set watchpoint #%d\n",no);
    }else{
      printf("Bad expression.\n");
    }
  }

  return 0;
}

static int cmd_d(char *args){
  char *arg = strtok(NULL, " ");
  if (args ==  NULL){ 
    printf("Press 'd number'\n");
    return 0;
  }else{
      int no = sscanf(args,"%d",&no);
      //printf("no:%d\n",no);
      if(!delete_watchpoint(no))
      printf("The watchpoint %s is no exist\n",arg);
    }
  return 0;
}

static int cmd_t(char *args){
	printf("Enter the number need to be calculated.Max number 10000\n");
	int test_num;
	if(scanf("%d",&test_num))		test_expr(test_num);
	else Log("Error number.\n");
	return 0;
}

static int cmd_sir(char *args){
	char *arg = strtok(NULL, " ");
	int step;
	if(args == NULL) step = 1;
	else sscanf(arg,"%d",&step);
	while(step)
	{ 
		cpu_exec(1);
		isa_reg_display();
		step--;
	}
	return 0;
	
}

/*static int cmd_point(char *args){
	char *pc = strtok(NULL," "); 
	long int cpu_pc = (long int)cpu.pc;
	int num=0;
	if(args == NULL) printf("Wrong point.Input point ADDR.\n");
	else
	{
		sscanf(args,"%s",pc);
		while(*pc != cpu_pc && num<128 && nemu_state.state != NEMU_RUNNING){
			printf("pc:%s,cpu.pc:%#lx\n",pc,cpu_pc);
			cpu_exec(1);
			num++;
		}
		cmd_info("r");
	}
	return 0;
}*/

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
	{ "si", "Execute n steps program", cmd_si},
	{ "info", "Print registers", cmd_info },
	{ "x", "x N EXPR.\tEvaluate the value of the expression EXPR and use the result as the starting memory address, output in hexadecimal form N consecutive 4 bytes" , cmd_x},
	{"p","p $eax+1\tEvaluate the value of the expression EXPR, which is supported by EXPR.",cmd_p},
  {"d","d no\tDelete the watchpoint.",cmd_d},
  {"w","w EXPR\tWhen the value of expression EXPR changes,program execution is suspended.",cmd_w},
	{"t","t\ttest cmd_p can success run.",cmd_t},
	{"sir", "sir N\tsi N and info r.",cmd_sir},	
	//{"point","point pc\tbreak point at $pc=addr.",cmd_point},
	/* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
