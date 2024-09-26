#ifndef PIX8_H
#define PIX8_H

#ifndef PIX8_RW
#define PIX8_RW 256
#endif
#ifndef PIX8_RH
#define PIX8_RH 192
#endif

#define PIX8_RWH PIX8_RW*PIX8_RH

#define abs(a)((a)>0?(a):-(a))
#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))
#define mid(a,b,c)(((b)<(a))?(a):(((b)>(c))?(c):(b)))

#include <stdint.h>
#include <stdbool.h>

typedef struct {
  uint8_t r,g,b;
} PIX8_RGB;

//--indexed an RGB buffers--//
uint8_t PIX8_B[PIX8_RWH];
PIX8_RGB PIX8_BRGB[PIX8_RWH];

//--Font and Pelette--//

const uint8_t PIX8_FONT[] = {
  0,3,0,3,0,3,3,0,3,0,3,0,3,0,3,0,3,0,0,3,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,3,3,3,3,3,3,3,0,3,3,3,3,0,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,3,0,3,3,3,0,3,0,3,0,3,3,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,3,0,0,0,3,0,0,0,3,3,0,3,3,3,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,3,0,3,0,3,3,3,0,3,0,0,0,3,3,0,0,0,0,0,0,3,0,0,0,3,0,3,3,0,0,3,3,3,3,0,3,3,3,3,3,3,3,3,3,3,0,3,3,3,3,0,3,3,3,0,0,3,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,3,3,0,3,3,0,3,3,0,3,3,0,3,3,3,3,0,3,3,0,3,0,3,3,0,0,0,0,0,3,0,3,0,3,3,3,3,3,3,0,0,0,3,3,0,3,0,3,0,3,0,0,0,0,3,3,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,3,0,0,0,3,0,0,3,3,0,3,3,0,0,3,0,0,0,0,3,3,0,3,3,3,3,0,3,0,0,0,0,0,3,0,3,3,3,0,3,0,3,0,3,3,0,3,3,3,3,3,0,3,0,3,0,0,0,0,3,0,3,3,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,3,0,0,0,3,3,0,3,3,3,0,0,3,3,0,0,0,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,3,3,3,0,3,0,3,0,3,0,0,0,3,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,3,0,3,0,3,3,3,3,3,0,0,3,0,3,3,3,0,3,0,0,3,0,0,3,0,3,0,3,0,0,0,3,3,0,3,3,0,0,3,3,3,3,0,3,3,0,3,3,0,3,3,0,3,3,0,3,3,3,0,0,3,0,3,0,3,3,0,3,3,3,3,0,3,0,3,0,3,0,3,3,3,3,0,0,3,0,0,3,3,0,0,3,0,0,0,0,0,0,3,0,3,0,3,3,3,0,0,0,3,0,0,0,0,3,0,0,0,0,3,0,3,0,3,3,3,0,3,0,3,3,3,0,0,0,0,3,0,3,0,3,0,3,0,3,3,0,0,3,3,3,3,3,0,3,3,3,3,3,0,0,3,3,3,3,0,0,3,0,0,0,0,3,0,3,0,0,0,0,0,0,0,3,0,0,3,3,0,0,3,3,3,0,3,0,3,0,3,3,0,3,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,3,0,0,0,3,0,0,0,3,3,0,3,3,3,0,0,3,3,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,3,0,3,0,3,0,0,0,3,0,0,0,3,0,0,0,3,0,3,0,0,0,0,0,0,0,3,3,3,3,0,3,3,0,0,3,0,3,3,0,0,3,3,0,3,0,3,3,3,3,0,3,0,3,0,3,3,3,0,3,0,0,3,0,3,3,0,3,3,0,3,3,3,3,3,3,3,3,3,0,0,3,3,0,3,0,3,0,3,3,0,3,3,3,3,3,0,3,0,3,0,3,3,0,3,3,0,0,3,0,0,3,3,3,3,3,0,3,0,0,0,0,3,3,3,0,3,0,3,0,3,3,0,3,0,0,0,0,3,0,0,3,0,3,0,3,0,3,0,3,0,0,0,0,0,0,3,0,3,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,3,3,3,3,3,3,3,0,0,3,3,3,3,3,3,0,0,3,0,3,0,0,0,3,0,3,3,3,0,3,0,0,3,0,0,3,0,3,3,3,3,0,3,0,3,0,0,0,0,3,0,3,0,0,3,3,0,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,3,3,0,3,3,3,0,0,3,3,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,3,3,0,0,0,3,0,3,3,3,0,3,3,3,3,0,0,0,3,0,3,3,3,3,0,3,3,3,3,0,3,3,3,3,0,0,3,3,3,3,0,3,3,3,3,3,3,3,3,0,3,3,3,3,3,0,3,3,0,3,3,3,3,3,0,0,0,0,3,3,0,3,3,3,3,0,3,0,3,3,3,0,3,0,3,3,3,3,0,3,0,3,0,3,3,3,0,3,3,0,3,0,3,3,0,3,0,0
};

const PIX8_RGB PIX8_PAL[] = {
  {0x1d,0x18,0x26},
  {0x8b,0x7f,0xb0},
  {0xc3,0xbe,0xe5},
  {0xff,0xe8,0xe9},
  {0x65,0x26,0x4e},
  {0xa0,0x1a,0x3d},
  {0xde,0x1b,0x45},
  {0xf2,0x63,0x7b},
  {0x8b,0x3f,0x39},
  {0xbb,0x45,0x31},
  {0xef,0x5d,0x0e},
  {0xff,0x95,0x00},
  {0x00,0xa0,0x3d},
  {0x12,0xd5,0x00},
  {0xb4,0xd8,0x00},
  {0xff,0xc3,0x1f},
  {0x00,0x6e,0x69},
  {0x00,0xae,0x85},
  {0x00,0xda,0xa7},
  {0x4f,0xd6,0xff},
  {0x2b,0x27,0x54},
  {0x3c,0x51,0xaf},
  {0x18,0x88,0xde},
  {0x00,0xa9,0xe1},
  {0x59,0x3c,0x97},
  {0x89,0x44,0xcf},
  {0xb4,0x4a,0xff},
  {0xe9,0x59,0xff},
  {0xe7,0x87,0x6d},
  {0xff,0xba,0x8c},
  {0xff,0xef,0x5c},
  {0xff,0x9c,0xde}
};

char* splice_wrap_text(const char* str,char ch,int n) {
  if (n <= 0) return NULL;
  int len = strlen(str);
  int new_len = len+(len/n);
  char* new_str = (char*)malloc(new_len+1);
  if (!new_str) return NULL;
  int j = 0;
  for (int i=0;i<len;i++) {
    new_str[j++] = str[i];
    if ((i+1)%n==0) {
      new_str[j++] = ch;
    }
  }
  new_str[j] = '\0';
  return new_str;
}

//--Drawing functions--//

void cls(uint8_t c) {
  memset(PIX8_B,c?c:0,PIX8_RWH);
}
void pset(int x,int y,uint8_t c) {
  if (x>=0&&x<PIX8_RW&&y>=0&&y<PIX8_RH) {
    PIX8_B[y*PIX8_RW+x] = c&31;
  }
}
uint8_t pget(int x,int y) {
  if (x>=0&&x<PIX8_RW&&y>=0&&y<PIX8_RH) {
    return PIX8_B[y*PIX8_RW+x];
  }
  return 0;
}
void psetrgb(int x,int y,PIX8_RGB c) {
  if (x>=0&&x<PIX8_RW&&y>=0&&y<PIX8_RH) {
    PIX8_BRGB[y*PIX8_RW+x] = c;
  }
}
PIX8_RGB pgetrgb(int x,int y) {
  if (x>=0&&x<PIX8_RW&&y>=0&&y<PIX8_RH) {
    return PIX8_BRGB[y*PIX8_RW+x];
  }
  return (PIX8_RGB){0,0,0};
}
void print(char* text,int x,int y,uint8_t c) {
  char* lines[256];
  int line_count = 0;
  char* text_copy = strdup(text);
  char* line = strtok(text_copy,"\n");
  while (line!=NULL&&line_count<256) {
    lines[line_count++]=line;
    line=strtok(NULL,"\n");
  }
  for (int l=0;l<line_count;l++) {
    char* cline = lines[l];
    for (int i=0;i<strlen(cline);i++) {
      int code = (int)(cline[i]);
      int cx = x+(i*4);
      int cy = y+(l*5);
      for (int j=0;j<4;j++) {
        for (int k=0;k<3;k++) {
          if (PIX8_FONT[((code-33)*3)+(j*282)+k]==3&&code>32) {
            pset(cx+k,cy+j,c);
          }
        }
      }
    }
  }
  free(text_copy);
}
void line(int x0,int y0,int x1,int y1,uint8_t c) {
  int dx = abs(x1-x0);
  int dy = abs(y1-y0);
  int sx = x0<x1?1:-1;
  int sy = y0<y1?1:-1;
  int err = (dx>dy?dx:-dy)/2;
  int e2;
  while (1) {
    pset(x0,y0,c);
    if (x0==x1&&y0==y1) break;
    e2 = err;
    if (e2>-dx){err-=dy;x0+=sx;}
    if (e2<dy){err+=dx;y0+=sy;}
  }
}
void rect(int x0,int y0,int x1,int y1,uint8_t c) {
  for (int x=x0;x<=x1;x++) {
    pset(x,y0,c);
    pset(x,y1,c);
  }
  for (int y=y0;y<=y1;y++) {
    pset(x0,y,c);
    pset(x1,y,c);
  }
}
void rectfill(int x0,int y0,int x1,int y1,uint8_t c) {
  for (int y=y0;y<=y1;y++) {
    for (int x=x0;x<=x1;x++) {
      pset(x,y,c);
    }
  }
}
void circ(int xc,int yc,int r,uint8_t c) {
  int x=0,y=r;
  int d=3-2*r;
  while (y>=x) {
    pset(xc+x,yc+y,c);
    pset(xc-x,yc+y,c);
    pset(xc+x,yc-y,c);
    pset(xc-x,yc-y,c);
    pset(xc+y,yc+x,c);
    pset(xc-y,yc+x,c);
    pset(xc+y,yc-x,c);
    pset(xc-y,yc-x,c);
    if (d<0) {
      d += 4*x+6;
    } else {
      d += 4*(x-y)+10;
      y--;
    }
    x++;
  }
}
void circfill(int xc,int yc,int r,uint8_t c) {
  int x=0,y=r;
  int d=3-2*r;
  while (y>=x) {
    for (int i=xc-x;i<=xc+x;i++) {
      pset(i,yc+y,c);
      pset(i,yc-y,c);
    }
    for (int i=xc-y;i<=xc+y;i++) {
      pset(i,yc+x,c);
      pset(i,yc-x,c);
    }
    if (d<0) {
      d += 4*x+6;
    } else {
      d += 4*(x-y)+10;
      y--;
    }
    x++;
  }
}
void trifill(int x0,int y0,int x1,int y1,int x2,int y2,uint8_t c) {
  if (y0>y1) { int tmpX = x0;int tmpY = y0;x0 = x1;y0 = y1;x1 = tmpX;y1 = tmpY; }
  if (y1>y2) { int tmpX = x1;int tmpY = y1;x1 = x2;y1 = y2;x2 = tmpX;y2 = tmpY; }
  if (y0>y1) { int tmpX = x0;int tmpY = y0;x0 = x1;y0 = y1;x1 = tmpX;y1 = tmpY; }
  int totalHeight = y2-y0;
  for (int y=y0;y<=y2;y++) {
    bool secondHalf = y>y1||y1==y0;
    int segmentHeight = secondHalf?(y2-y1):(y1-y0);
    float alpha = (float)(y-y0)/totalHeight;
    float beta = (float)(y-(secondHalf?y1:y0))/segmentHeight;
    int ax = x0+(x2-x0)*alpha;
    int bx = secondHalf?(x1+(x2-x1)*beta):(x0+(x1-x0)*beta);
    if (ax>bx) {
      int tmp = ax;
      ax = bx;
      bx = tmp;
    }
    for (int x=ax;x<=bx;x++) {
      pset(x,y,c);
    }
  }
}

void make_rgb() {
  for (int i=0;i<PIX8_RWH;++i) {
    PIX8_BRGB[i] = PIX8_PAL[PIX8_B[i]];
  }
}

#endif