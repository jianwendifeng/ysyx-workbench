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

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif	
