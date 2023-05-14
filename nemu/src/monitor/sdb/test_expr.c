#include <stdio.h>
#include <isa.h>

word_t expr();

int test_expr(int n){
	FILE *fp = fopen("/home/todas/ysyx-workbench/nemu/tools/gen-expr/input","r");	//open input file
	if(fp == NULL){
		printf("Failed to open the 'input' file.\n ");
		return 1;
	}
	char buf[1024+128];
	char expr_buf[1024];

	int answer,i=0,k=0;
	bool success;
	int result;
	while(fgets(buf,1024,fp) != NULL && n--){						//逐行扫描
		sscanf(buf,"%d %[^\n]",&answer,expr_buf);
		printf("buf:%s\n",buf);
		result = expr(buf,&success);
		i++;
		if((!success)&&(result != answer)) {
			printf("Failed to calculate the exprission.\t %s\nCorrect answer is %d.\tExpr answer is %d.\n",buf,answer,result);
	}
		else {
			k++;
		}
		printf("The %d exprissions had success calculted.\n",k);
		printf("There %d exprissions had  calculted.\n",i);
	}
	fclose(fp);

	return 0;
}
