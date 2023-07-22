#include <am.h>
#include <nemu.h>
#include <stdio.h>

#define KEYDOWN_MASK 0x8000
#define KEY_NONE 0

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  // kbd->keydown = 0;
  // kbd->keycode = AM_KEY_NONE;
  int kb = inl(KBD_ADDR);
  kbd->keydown = (kb & KEYDOWN_MASK ? true : false); //1000000000000000 true
  //kbd->keycode = (kbd->keydown) ? kb & ~KEYDOWN_MASK : KEY_NONE ;   //清除键盘扫描码中表示按键按下状态的最高位。
  kbd->keycode =  kb & ~KEYDOWN_MASK;
}
