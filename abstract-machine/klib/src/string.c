#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 1;
  while(s[len] != '\0')
  {
    len++;
  }
  return len;
}

char *strcpy(char *dst, const char *src) {
  size_t i;
	for(i = 0 ; src[i] != '\0' ; i++){
		dst[i] = src[i];
	}
	dst[i+1] = '\0';
 return dst;	
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
  for(i = 0 ; (i < n) && (src[i] != '\0') ; i++)
  {
    dst[i] = src[i];
  }

  while(i < n){
    dst[i] = '\0';
		i++;
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  size_t len = strlen(dst);
  size_t i;
	for(i=0;src[i]!='\0';i++){
		dst[len+i] = src[i];
	}
	dst[len+i+1] = '\0';
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  int i=0;
  while((s1[i] != '\0') || (s2[i] != '\0')){
    if(s1[i] < s2[i]) return -1;
    else if(s1[i] > s2[i]) return 1;
		i++;
  }
  return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  int i=0;
  while(i !=  n){
    if(s1[i] < s2[i]) return -1;
    else if(s1[i] > s2[i]) return 1;
		else if(s1[i] == '\0') return 0;
		i++;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  unsigned char *p = (unsigned char *)s;
  while(n > 0){
    *p = (unsigned char)c;
    p++;
    n--;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  unsigned char *pdst = (unsigned char*)dst;
  const unsigned char *psrc = (const unsigned char*)src;
  size_t i;
  if(pdst == psrc) return dst;
  else if(pdst < psrc){
    for(i = 0 ; i < n ; i++){
      pdst[i] = psrc[i];
    }
  }
  else{
    for(i = n ; i > 0 ; i--){
      pdst[i-1] = psrc[i-1];
    }
  }
  return dst;
} 

void *memcpy(void *out, const void *in, size_t n) {
  unsigned char *pout = (unsigned char*)out;
  const unsigned char *pin = (const unsigned char*)in;
  while(n){ 
    pout[n-1] = pin[n-1];
		n--;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *ps1 = (const unsigned char*)s1;
  const unsigned char *ps2 = (const unsigned char*)s2;
  size_t i;
  for(i = 0  ; i < n ; i++){
    if(ps1[i] < ps2[i]) return -1;
    else if(ps1[i] > ps2[i]) return 1;
  }
  return 0;
}

#endif
