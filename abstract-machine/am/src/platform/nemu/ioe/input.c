#include <am.h>
#include <nemu.h>
#include <stdio.h>

#define KEYDOWN_MASK 0x8000
// #define KEY_NONE 0

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  // kbd->keydown = 0;
  // kbd->keycode = AM_KEY_NONE;
  int kb = inl(KBD_ADDR);
  kbd->keydown = (kb & KEYDOWN_MASK ? true : false);
  
  kbd->keycode = kb & ~KEYDOWN_MASK ;
  if(kbd->keydown)printf("\n\nkb%d\tkeycode%d\n\n",kb,kbd->keycode);
}
