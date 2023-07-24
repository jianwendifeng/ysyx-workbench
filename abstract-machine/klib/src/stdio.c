#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#define SIZE_MAX_BUF 128

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}


void reverse(char* num,int len,char* out){

    int start = 0;
    int end = len- 1;
    
    while(start < len){
        *out = num[end] +'0';
        out++;
        start++;
        end--;
    }
}

int itoa(int num,char *out,int base){
	int len = 0;
	char temp[SIZE_MAX_BUF]; 
	int i = 0;
    if(num == 0) {
    	*out++ = 0;
    	len++;
    	return len;
	}
	if(num < 0 ){
		*out++ = '-';
		len++;
		num = -num;
	}
	
	do{
    	temp[i] = (num % base) ;
    //	printf("temp[%d]:%d\n",i,temp[i]);
    	i++;
    	num = num / base;
    	len++;

	}while(num  != 0 );
	reverse(temp,i,out);
    return len;
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
                    int i = itoa(tmp_int,out,10);
                    out += i;
                    len += i;
                    break;
                case 's':
                    fmt++;
                    char *tmp_ch = va_arg(ap,char*);
                     while (*tmp_ch != '\0') {
                        out[++len] = *tmp_ch++;
                    }
                    break;
                default:
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
  int i = 0 ;
  while (i<SIZE_MAX_BUF){
    out[i++] = 0;
  }
  va_list args;
  int len = 0;
	
  va_start(args,fmt);
  len = vsprintf(out,fmt,args);
  va_end(args);

  return len;
}


int printf(const char *fmt, ...) {
  va_list ap;
  char buf[SIZE_MAX_BUF];
   int i = 0 ;
  while (i<SIZE_MAX_BUF){
    buf[i++] = 0;
  }
  va_start(ap, fmt);
  int len = vsprintf(buf, fmt, ap);
  va_end(ap);
  i=0;
  while(i < len){
    putch(buf[i++]);
  }
  return 0;
}




#endif	
