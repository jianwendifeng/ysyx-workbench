#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
#define BUF_SIZE 1024

// 用于反转指定字符串
static void reserve(char *s, int len) {
  char *end = s + len - 1;
  char tmp;
  while (s < end) {
    tmp = *s;
    *s = *end;
    *end = tmp;
    s++;
    end--;
  }
  return;
}

int itoa( int value, char *string,int radix) { // FIXME:不是标准实现
  assert (radix <= 36);
  int positive = value >= 0; // sign
  int bit = 0; // 用来记录某一位的数字
  size_t i = 0; // 用来记录当前长度的
  if (!positive) value = -value;
  do
  { // FIXME:HERE
    bit = value % radix;
    if (bit >= 10) { string[i++] = 'a' + bit - 10; }// 16进制中大于10的表示
    else { putstr(string); string[i++] = '0' + bit; }
    
  } while ((value /= radix) > 0);
  if (!positive) string[i++] = '-';
  string[i] = '\0';
  reserve(string, i);
  return i;
}

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

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  assert(NULL != out);
  assert(NULL != fmt);

  int count;
  int fmt_index;

  for (count = 0, fmt_index = 0; fmt[fmt_index] != '\0' && count < n;)
  {
    if (fmt[fmt_index] != '%') { 
      out[count] = fmt[fmt_index];
      count++;
      fmt_index++;
    } else {
      switch (fmt[fmt_index+1])
      {
      case '%':
        out[count] = fmt[fmt_index];
        count++;
	      fmt_index += 2;
        break;
      case 'd':
        count += itoa(va_arg(ap, int), out+count, 10);
        fmt_index += 2;
        break;
      case 's':
        strcpy(out+count, va_arg(ap, char*));
        count += strlen(out + count);
        fmt_index += 2;
        break;
      case 'c':
        out[count] = (char)va_arg(ap, int);
        count++;
        fmt_index += 2;
        break;
      default:
        out[count] = fmt[fmt_index];
	    	out[count+1] = fmt[fmt_index+1];
	    	count += 2;
	    	fmt_index += 2;
        break;
      }
    }
  }
  out[count] = '\0';
  return count;
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



#endif	
