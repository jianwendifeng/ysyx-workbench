#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// void reverse(char s[]) {
//     int q, w;
//     char temp;
    
//     for (q = 0, w = strlen(s)-1; q < w; q++, j--) {
//         temp = s[q];
//         s[q] = s[j];
//         s[j] = temp;
//     }
// }

// void itoa(int n,char s[]){
//        int m = 0;
//        do{
//           s[m++] = n %10 +'0';
//        }while((n /= 10) > 0);
//        reverse(s);
// }

#define BUF_SIZE 1024


int num_to_string(char *buffer, int num) {
    int digits = 0;

    if (num < 0) {
        *buffer++ = '-';
        num = -num;
        digits++;
    }

    if (num == 0) {
        *buffer++ = '0';
        digits++;
    } else {
        int rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + (num % 10);
            num /= 10;
            digits++;
        }
        while (rev_num > 0) {
            *buffer++ = '0' + (rev_num % 10);
            rev_num /= 10;
        }
    }

    return digits;
}



int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
   char *p = out;
    const char *fmt_p = fmt;

    while (*fmt_p != '\0') {
        if (*fmt_p == '%') {
            fmt_p++;
            switch (*fmt_p) {
                case 's': {
                    char *str = va_arg(ap, char *);
                    while (*str != '\0') {
                        *p++ = *str++;
                    }
                    break;
                }
                case 'd': {
                    int num = va_arg(ap, int);
                    int digits = num_to_string(p, num);
                    p += digits;
                    break;
                }
                default:
                    // Handle unsupported format specifier
                    *p++ = '%'; // Write the original '%' character
                    *p++ = *fmt_p;
                    break;
            }
        } else {
            *p++ = *fmt_p;
        }
        fmt_p++;
    }

    *p = '\0';
    return p - out;
}

int sprintf(char *out, const char *fmt, ...)
{
  va_list args;
  int ret;

  va_start(args,fmt);
  ret = vsprintf(out,fmt,args);
  va_end(args);

  return ret;
}
// int sprintf(char *out, const char *fmt, ...) {
// 	va_list ap;
//   va_start(ap, fmt);      //把参数列表拷贝到ap中,
//   int len=0;
//   int arg_i;
//   char arg_i_s[64];
//   char *arg_s;
//   int i = 0;

//   while(fmt[i] != '\0')
//   {
//     if(fmt[i] == '%')
//     {
//       i++;  //fmt指针移动到%后面
//       switch(fmt[i])
//       {
//         case 's': {
//            arg_s = va_arg(ap,char*);
//             for(int j = 0 ; arg_s[j] != '\0' ; j++){
//             out[len++] = arg_s[j];
//             }
//             i++;  //执行完成后fmt的指针再次后移
//              break;
//          }
//        case 'd': {
//            arg_i = va_arg(ap,int);  
//            itoa(arg_i,arg_i_s);
//            for(int j = 0 ; arg_i_s[j] != '\0' ; j++){
//              out[len++] = arg_i_s[j];
//            }
//             i++;
//            break;
//          }
//        default:{
//          out[len++] = fmt[i++];
//        }
//       }
//     } else{
//       out[len++] = fmt[i++];
//     }
//   }
//   out[len++] = '\0';
//   va_end(ap);
//   return len;
// }

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif	
