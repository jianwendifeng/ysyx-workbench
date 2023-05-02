#include <stdio.h>
#include <isa.h>

word_t expr();

int test_expr(int n){
	FILE *fp = fopen("/home/todas/ysyx-workbench/nemu/tools/gen-expr/input","r");	//open input file
	if(fp == NULL){
		printf("Failed to open the 'input' file.\n ");
		return 1;
	}
	char buf[65535+128];
	char expr_buf[65535];

	int answer,i=0;
	bool success,result;
	while(fgets(buf,65535,fp) != NULL){						//逐行扫描
		sscanf(buf,"%d %[^\n]",&answer,expr_buf);
		result = expr(buf,&success);
		if((!success) && (answer != result)) {
			printf("Failed to calculate the exprission.\t %s\nCorrect answer is %d.\tExpr answer is %d.\n",buf,answer,result);
	}
		else {
			i++;
			printf("The %d exprissions had success calculted.\n",i);
		}
		printf("NO %d exprissions had success calculted.\n",i);
	
	}
	fclose(fp);

	return 0;
}
