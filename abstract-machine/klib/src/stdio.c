#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
#define SIZE_MAX_BUF 1024


void reverse(char str[],int len,char* out){
    int start = 0;
    int end = len -1;
    while(start < len){
        *out++ = str[end] + '0';
        start++;
        end--;
    }
}

static char* itoa(int num,int base,int len){
    len = 0;
	char temp[SIZE_MAX_BUF]; 
	int i = 0;
    char *out = {0};
    if(num == 0) {
    	*out++ = 0;
    	len++;
    	return out;
	}
	if(num < 0 ){
		*out++ = '-';
		len++;
		num = -num;
	}
	
	do{
    	temp[i] = (num % base) ;
    	i++;
    	num = num / base;
    	len++;

	}while(num  != 0 );
	reverse(temp,i,out);
    return out;
}


int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
     int len = 0;
    while(*fmt != '\0'){
        if(*fmt != '%' ){
        	*out++ = *fmt++; 
        	len++;
        }
        else{
        	
            switch (*++fmt){
                case 'd':
                	fmt++;
                    int tmp_int = va_arg(ap,int);
                    // int i = itoa(tmp_int,out,10);
                    int i = 0;
                    char *int_char = itoa(tmp_int,10,i);
                    len += i;
                    do{
                        *out++ = *int_char++; 
                    }
                    while(i--);
                    break;
                case 's':
                    fmt++;
                    char *tmp_ch = va_arg(ap,char*);
                     while (*tmp_ch != '\0') {
                        out[len++] = *tmp_ch++;
                    }
                    break;
                default:
                    out[len++] = *fmt++;
                    out[len++] = *fmt++;
                    break;
            }
        }
    }
    out[len] = '\0';
    return len;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
    int count = 0;
    count = vsnprintf(out, SIZE_MAX_BUF, fmt, ap);
    return count;
}

int sprintf(char *out, const char *fmt, ...)
{   
    for (int i = 0; i < SIZE_MAX_BUF; i++) {
        out[i] = 0; // 初始化 buf 缓冲区为全零
    }
    va_list args;
    int len = 0;
	
    va_start(args,fmt);
    len = vsprintf(out,fmt,args);
    va_end(args);

    return len;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}



int printf(const char *fmt, ...) {
    va_list args;
    va_start(args,fmt);
    int len;
    while(*fmt != '\0'){
        if(*fmt == '%'){
            fmt++;
            switch (*fmt){
                case 'd':
                    fmt++;
                	int tmp_int = va_arg(args,int);
                    char* temp = itoa(tmp_int,10,len);
                    do{
                        putch(*temp++);
                    }while(len--);
                case 's':
                    fmt++;
                    char* tmp_ch = va_arg(args,char*);
                    while(*tmp_ch != '\0'){
                        putch(*tmp_ch++);
                    }
                    break;  
                default:
                    putch(*fmt++);
                    break;
            }
        }
    }
    
    va_end(args);
    //panic("Not implemented");
    return 0;
}


#endif	
