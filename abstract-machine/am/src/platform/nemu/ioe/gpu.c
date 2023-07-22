#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

#define W 400
#define H 300

void __am_gpu_init() {
  int i;
  int w = W;  // TODO: get the correct width
  int h = H;  // TODO: get the correct height
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (i = 0; i < w * h; i ++) fb[i] = i;
  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
   *cfg = (AM_GPU_CONFIG_T) {
    .present = true, 
    .has_accel = false,
    .width = W, 
    .height = H,
    .vmemsz = W*H*sizeof(uint32_t)
  };
}

//fb[(y+j)*W+(x+i)] = *(pixels+j*w+i);



void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int x = ctl->x , y = ctl->y , w = ctl->w , h = ctl->h;
  uint32_t* pixels = (uint32_t *)ctl->pixels;
  uint32_t* fb = (uint32_t *)(uintptr_t)FB_ADDR;
  //if((!w) || (!h)) return ;

// for(int j = 0; j< h; j++){
//     for(int i = 0; i< w; i++){
//       fb[(y+j)*W+(x+i)] = *(pixels+j*w+i);
//     }
//   }

  for(int i=0; i <= h ; i++){          //i is height
    for(int j = 0 ; j <=w ; j++){     //j is weight
      fb[x+j+(y+i)*W] = pixels[w*i+j];
    }
  }

  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
