#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
#define SIZE_MAX_VSPRINTF 1024


void reverse(char* str,int len,char* output){
    int start = 0;
    while(start < len){
        *output++ = str[start++];
    }
}

static int itoa(int num,char *fmt,int base){
    int i = 0;
    int neg = 0;
    char *str;
    if(num == 0){
        *fmt++ = '0';
        return i++;
    }
    else if(num < 0 && base == 10){     //negetive
        neg = 1;
        num = -num;
    }

    while(num != 0){
        int tmp = num % base;
        *str++ = tmp;
        i++;
    }

    if(neg == 1){
        *fmt++ = '-';
        i++;
    }
    reverse(str,i,fmt);
    
    return i;
}


int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
    int len = 0;
    while(fmt[len] != '\0'){
        if(fmt[len] != '%' ){
            out[len++] = *fmt++;
        }
        else{
            switch (fmt[len+1]){
                case 'd':
                    int tmp_int = va_arg(ap,int);
                    len += itoa(tmp_int,out,10);
                    break;
                case 's':
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

    out[len++] = '\0';
    return len;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
    int count = 0;
    count = vsnprintf(out, SIZE_MAX_VSPRINTF, fmt, ap);
    return count;
}

int sprintf(char *out, const char *fmt, ...)
{
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
//   va_list args;
//   va_start(args,fmt);
//   char ch;
//   while(*fmt != '\0'){
//     if(ch == '%'){
//         fmt++;
//         if(*fmt ==)
//     }
//   }
panic("Not implemented");
}


#endif	
