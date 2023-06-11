#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>


#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

void reverse(char s[]) {
    int i, j;
    char temp;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa(int n,char s[]){
	int i,sign;

	if((sign = n) < 0){
		n = -n;
	}
	i=0;
	do{
		s[i++] = n%10 +'0';
	}while((n /= 10) > 0);

	if(sign < 0)
	{
		s[i++] = '-';
	}	
	reverse(s);
}


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
  int arg_i;
  char arg_i_s[1024];
  char *arg_s;
  int i=0;

  while(fmt[i] != '\0'){
    if(fmt[i] == '%'){
      switch(fmt[i+1])
      {
        case 's':
        {
          arg_s = va_arg(ap,char *);
          for(int j = 0; arg_s[j] != '\0';j++){
            out[len] = arg_s[j];
						len++;
          }
          i += 2;
          break;
        }

        case 'd':
       {
        arg_i = va_arg(ap,int);
        itoa(arg_i,arg_i_s);
        for(int j = 0;arg_i_s[j] != '\0';j++){
          out[len] = arg_i_s[j];
					len++;
        }

        i += 2;
        break;
       }

        default:
        {
          out[len] = fmt[i];
					len++;
          i++;
          break;
        }
      }
    }
    else{
          out[len] = fmt[i];
					len++;
          i++;
    }
  }
  out[len+1] = '\0';
  va_end(ap);
  return len++;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif	
