#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)


void reverse(char str[],int len){
    int start = 0;
    int end = len - 1;
    while(start < end){
        char tmp = str[start];
        str[start++] = str[end];
        str[end++] = tmp;
    }
}

static int itoa(int num,char *str,int base){
    int i = 0;
    int neg = 0;
    if(num == 0){
        str[i] = '0';
        return i;
    }
    else if(num < 0 && base == 10){     //10进制
        neg = 1;
        num = -num;
    }

    while(num != 0){
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if(neg == 1){
        str[i++] = '-';
    }

    str[i] = '\0';
    reverse(str,i);
    return i;
}


int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
    int len = 0;
    while(*fmt != '\0'){
        if(fmt[len] != '%' ){
            *out++ = *fmt++;
            len++ ;
        }
        else{
            switch (*fmt){
                case 'd':
                    len += itoa(va_arg(ap,int),out,10);
                    break;
                case 's':
                    char *ch = va_arg(ap,char*);
                    char *tmp = ch;
                     while (*tmp != '\0') {
                        *out++ = *tmp++;
                        len++;
                    }
                    break;
                default:
                    *out++ = *fmt++;
                    len++;
                    break;
            }
        }
        
    }
    out[len++] = '\0';
    return len;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
    int count = 0;
    count = vsnprintf(out, SIZE_MAX, fmt, ap);
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
