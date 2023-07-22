#include <am.h>
#include <nemu.h>
#include <stdio.h>

#define KEYDOWN_MASK 0x8000
// #define KEY_NONE 0

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  // kbd->keydown = 0;
  // kbd->keycode = AM_KEY_NONE;
  uint32_t kb = inl(KBD_ADDR);
  kbd->keydown = (kb & KEYDOWN_MASK ? true : false);
  if(kbd->keydown)printf("kb%ld\n",kb);
  kbd->keycode = kb & ~KEYDOWN_MASK ;
}
