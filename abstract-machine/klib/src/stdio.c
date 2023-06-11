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
	va_start(ap, fmt);	//把参数列表拷贝到ap中
  int i = 0;
  char* buf = out;

  while(*fmt != '\0')
  {
    if(*fmt == '%')
    {
      fmt++;  //指针移动到%后面
      switch(*fmt)
			{
				case 's': 
					{
						char *s = va_arg(ap,char*);	
						int len = strlen(s);
						strncpy(buf,s,len);
						buf += len;
						i++;
						break;}
				case 'd': 
					{
						int d = va_arg(ap,int);
						int len = sprintf(buf,"%d",d);
						buf += len;
						i += len;
						break;
					}
				default:
					return -1;
			}
		}
		
  }
  *buf = '\0';
  va_end(ap);
  return i;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif	
