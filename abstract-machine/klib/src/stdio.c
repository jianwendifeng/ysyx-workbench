#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);	//把参数列表拷贝到ap中,
  int len=0;


  while(fmt[len] != '\0'){
    if(fmt[len] == '%'){
      switch(fmt[len+1])
      {
        case 's':
        {
          char* str = va_arg(ap,char*);
          while(*str != '\0'){
            out[len++] = *str++;
          }
          break;
        }

        case 'd':
       {
        int num = va_arg(ap,int);
        out[len++] = num;
        break;
       }

        default:
        {
          out[len++] = *fmt;
          break;
        }
      }
    }
    else{
       out[len++] = *fmt;
    }
    fmt++;
  }
  out[len++] = '\0';
  va_end(ap);
  return len;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif	
