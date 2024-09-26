#include <stdint.h>
#include <stdbool.h>

#define abs(a)((a)>0?(a):-(a))
#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))
#define mid(a,b,c)(((b)<(a))?(a):(((b)>(c))?(c):(b)))

typedef struct {
  uint8_t r,g,b;
} RGB;

const uint8_t font[] = {
  0,3,0,3,0,3,3,0,3,0,3,0,3,0,3,0,3,0,0,3,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,3,3,3,3,3,3,3,0,3,3,3,3,0,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,3,0,3,3,3,0,3,0,3,0,3,3,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,3,0,0,0,3,0,0,0,3,3,0,3,3,3,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,3,0,3,0,3,3,3,0,3,0,0,0,3,3,0,0,0,0,0,0,3,0,0,0,3,0,3,3,0,0,3,3,3,3,0,3,3,3,3,3,3,3,3,3,3,0,3,3,3,3,0,3,3,3,0,0,3,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,3,3,0,3,3,0,3,3,0,3,3,0,3,3,3,3,0,3,3,0,3,0,3,3,0,0,0,0,0,3,0,3,0,3,3,3,3,3,3,0,0,0,3,3,0,3,0,3,0,3,0,0,0,0,3,3,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,3,0,0,0,3,0,0,3,3,0,3,3,0,0,3,0,0,0,0,3,3,0,3,3,3,3,0,3,0,0,0,0,0,3,0,3,3,3,0,3,0,3,0,3,3,0,3,3,3,3,3,0,3,0,3,0,0,0,0,3,0,3,3,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,3,0,0,0,3,3,0,3,3,3,0,0,3,3,0,0,0,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,3,3,3,0,3,0,3,0,3,0,0,0,3,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,3,0,3,0,3,3,3,3,3,0,0,3,0,3,3,3,0,3,0,0,3,0,0,3,0,3,0,3,0,0,0,3,3,0,3,3,0,0,3,3,3,3,0,3,3,0,3,3,0,3,3,0,3,3,0,3,3,3,0,0,3,0,3,0,3,3,0,3,3,3,3,0,3,0,3,0,3,0,3,3,3,3,0,0,3,0,0,3,3,0,0,3,0,0,0,0,0,0,3,0,3,0,3,3,3,0,0,0,3,0,0,0,0,3,0,0,0,0,3,0,3,0,3,3,3,0,3,0,3,3,3,0,0,0,0,3,0,3,0,3,0,3,0,3,3,0,0,3,3,3,3,3,0,3,3,3,3,3,0,0,3,3,3,3,0,0,3,0,0,0,0,3,0,3,0,0,0,0,0,0,0,3,0,0,3,3,0,0,3,3,3,0,3,0,3,0,3,3,0,3,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,3,0,0,0,3,0,0,0,3,3,0,3,3,3,0,0,3,3,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,3,0,3,0,3,0,0,0,3,0,0,0,3,0,0,0,3,0,3,0,0,0,0,0,0,0,3,3,3,3,0,3,3,0,0,3,0,3,3,0,0,3,3,0,3,0,3,3,3,3,0,3,0,3,0,3,3,3,0,3,0,0,3,0,3,3,0,3,3,0,3,3,3,3,3,3,3,3,3,0,0,3,3,0,3,0,3,0,3,3,0,3,3,3,3,3,0,3,0,3,0,3,3,0,3,3,0,0,3,0,0,3,3,3,3,3,0,3,0,0,0,0,3,3,3,0,3,0,3,0,3,3,0,3,0,0,0,0,3,0,0,3,0,3,0,3,0,3,0,3,0,0,0,0,0,0,3,0,3,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,3,3,3,3,3,3,3,0,0,3,3,3,3,3,3,0,0,3,0,3,0,0,0,3,0,3,3,3,0,3,0,0,3,0,0,3,0,3,3,3,3,0,3,0,3,0,0,0,0,3,0,3,0,0,3,3,0,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,3,3,0,3,3,3,0,0,3,3,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,3,3,0,0,0,3,0,3,3,3,0,3,3,3,3,0,0,0,3,0,3,3,3,3,0,3,3,3,3,0,3,3,3,3,0,0,3,3,3,3,0,3,3,3,3,3,3,3,3,0,3,3,3,3,3,0,3,3,0,3,3,3,3,3,0,0,0,0,3,3,0,3,3,3,3,0,3,0,3,3,3,0,3,0,3,3,3,3,0,3,0,3,0,3,3,3,0,3,3,0,3,0,3,3,0,3,0,0
};

const RGB palette[] = {
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

char* wrap_text(char* str,int n) {
  int len = strlen(str);
  int new_len = len+(len/n);
  char* wrapped = (char*)malloc(new_len+1);
  if (!wrapped) return NULL;
  int j = 0;
  for (int i=0;i<len;i++) {
    wrapped[j++] = str[i];
    if ((i+1)%n==0) {
      wrapped[j++] = '\n';
    }
  }
  wrapped[j] = '\0';
  return wrapped;
}

void cls(uint8_t* b,int w,int h,uint8_t c) {
  memset(b,c?c:0,w*h);
}
void pset(uint8_t* b,int w,int h,int x,int y,uint8_t c) {
  if (x>=0&&x<w&&y>=0&&y<h) {
    b[y*w+x] = c&31;
  }
}
uint8_t pget(uint8_t* b,int w,int h,int x,int y) {
  if (x>=0&&x<w&&y>=0&&y<h) {
    return b[y*w+x];
  }
  return 0;
}
void print(uint8_t* b,int w,int h,char* text,int x,int y,uint8_t c) {
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
          if (font[((code-33)*3)+(j*282)+k]==3&&code>32) {
            pset(b,w,h,cx+k,cy+j,c);
          }
        }
      }
    }
  }
  free(text_copy);
}
void line(uint8_t* b,int w,int h,int x0,int y0,int x1,int y1,uint8_t c) {
  int dx = abs(x1-x0);
  int dy = abs(y1-y0);
  int sx = x0<x1?1:-1;
  int sy = y0<y1?1:-1;
  int err = (dx>dy?dx:-dy)/2;
  int e2;
  while (1) {
    pset(b,w,h,x0,y0,c);
    if (x0==x1&&y0==y1) break;
    e2 = err;
    if (e2>-dx){err-=dy;x0+=sx;}
    if (e2<dy){err+=dx;y0+=sy;}
  }
}
void rect(uint8_t* b,int w,int h,int x0,int y0,int x1,int y1,uint8_t c) {
  for (int x=x0;x<=x1;x++) {
    pset(b,w,h,x,y0,c);
    pset(b,w,h,x,y1,c);
  }
  for (int y=y0;y<=y1;y++) {
    pset(b,w,h,x0,y,c);
    pset(b,w,h,x1,y,c);
  }
}
void rectfill(uint8_t* b,int w,int h,int x0,int y0,int x1,int y1,uint8_t c) {
  for (int y = y0; y <= y1; y++) {
    for (int x = x0; x <= x1; x++) {
      pset(b, w, h, x, y, c);
    }
  }
}
void circ(uint8_t* b, int w, int h, int xc, int yc, int r, uint8_t c) {
  int x=0,y=r;
  int d=3-2*r;
  while (y>=x) {
    pset(b,w,h,xc+x,yc+y,c);
    pset(b,w,h,xc-x,yc+y,c);
    pset(b,w,h,xc+x,yc-y,c);
    pset(b,w,h,xc-x,yc-y,c);
    pset(b,w,h,xc+y,yc+x,c);
    pset(b,w,h,xc-y,yc+x,c);
    pset(b,w,h,xc+y,yc-x,c);
    pset(b,w,h,xc-y,yc-x,c);
    if (d<0) {
      d += 4*x+6;
    } else {
      d += 4*(x-y)+10;
      y--;
    }
    x++;
  }
}
void circfill(uint8_t* b,int w,int h,int xc,int yc,int r,uint8_t c) {
  int x=0,y=r;
  int d=3-2*r;
  while (y>=x) {
    for (int i=xc-x;i<=xc+x;i++) {
      pset(b,w,h,i,yc+y,c);
      pset(b,w,h,i,yc-y,c);
    }
    for (int i=xc-y;i<=xc+y;i++) {
      pset(b,w,h,i,yc+x,c);
      pset(b,w,h,i,yc-x,c);
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
void trifill(uint8_t* b, int w, int h, int x0, int y0, int x1, int y1, int x2, int y2, uint8_t c) {
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
      pset(b,w,h,x,y,c);
    }
  }
}