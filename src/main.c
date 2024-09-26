#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "lib/stb_image_write.h"

#define PIX8_RW 512
#define PIX8_RH 512
#include "lib/PIX8_B.h"


int main() {
  cls(0);
  /*for (int x=0;x<PIX8_RW;x++) {
    for (int y=0;y<PIX8_RH;y++) {
      pset(x,y,x^y);
    }
  }*/
  int w = PIX8_RW;
  int sz = 8;
  int sz1 = sz-1;
  int w2 = w/2;
  int w4 = w/4;
  int w8 = w/8;
  for (int x=0;x<w2;x++) {
    for (int y=0;y<w2;y++) {
      for (int z=0;z<w2;z++) {
        int a = x/sz;
        int b = z/sz;
        int c = y/sz;
        int d = max(max(abs(a-w4/sz+0.5),abs(b-w4/sz+0.5)),abs(c-w4/sz+0.5));
        int k = a^b^c;
        if (k%(d*2+1)==0) {
          int i = x+w8+z/2;
          int j = y+w8-z/2+w4;
          int s = (y&sz1)==0?0:((x&sz1)==sz1?20:40);
          PIX8_RGB col = PIX8_PAL[d&31];
          PIX8_RGB c = {max(col.r-s,0),max(col.g-s,0),max(col.b-s,0)};
          psetrgb(i,j,c);
        }
      }
    }
  }
  stbi_write_png("output.png",PIX8_RW,PIX8_RH,3,PIX8_BRGB,PIX8_RW*3);
  printf("Press Enter to exit...\n");
  getchar();
  return 0;
}