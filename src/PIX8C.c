#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "lib/stb_image_write.h"
#include "lib/PIX8C.h"

#define WIDTH 256
#define HEIGHT 192

uint8_t BUFFER[WIDTH*HEIGHT];
RGB BUFFERO[WIDTH*HEIGHT];

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int mouse_x = 0;
int mouse_y = 0;
int mouse_btn = 0;
int wheel_x = 0;
int wheel_y = 0;
int fullscreen = 0;

int lua_cls(lua_State *L) {
  cls(BUFFER,WIDTH,HEIGHT,luaL_checknumber(L,1));
  return 0;
}
int lua_pset(lua_State *L) {
  pset(BUFFER,WIDTH,HEIGHT,luaL_checknumber(L,1),luaL_checknumber(L,2),luaL_checknumber(L,3));
  return 0;
}
int lua_pget(lua_State *L) {
  lua_pushnumber(L,pget(BUFFER,WIDTH,HEIGHT,luaL_checknumber(L,1),luaL_checknumber(L,2)));
  return 1;
}
int lua_print(lua_State *L) {
  print(BUFFER,WIDTH,HEIGHT,luaL_checkstring(L,1),luaL_checknumber(L,2),luaL_checknumber(L,3),luaL_checknumber(L,4));
  return 0;
}
int lua_line(lua_State *L) {
  line(BUFFER,WIDTH,HEIGHT,luaL_checknumber(L,1),luaL_checknumber(L,2),luaL_checknumber(L,3),luaL_checknumber(L,4),luaL_checknumber(L,5));
  return 0;
}
int lua_rect(lua_State *L) {
  rect(BUFFER,WIDTH,HEIGHT,luaL_checknumber(L,1),luaL_checknumber(L,2),luaL_checknumber(L,3),luaL_checknumber(L,4),luaL_checknumber(L,5));
  return 0;
}
int lua_rectfill(lua_State *L) {
  rectfill(BUFFER,WIDTH,HEIGHT,luaL_checknumber(L,1),luaL_checknumber(L,2),luaL_checknumber(L,3),luaL_checknumber(L,4),luaL_checknumber(L,5));
  return 0;
}
int lua_circ(lua_State *L) {
  circ(BUFFER,WIDTH,HEIGHT,luaL_checknumber(L,1),luaL_checknumber(L,2),luaL_checknumber(L,3),luaL_checknumber(L,4));
  return 0;
}
int lua_circfill(lua_State *L) {
  circfill(BUFFER,WIDTH,HEIGHT,luaL_checknumber(L,1),luaL_checknumber(L,2),luaL_checknumber(L,3),luaL_checknumber(L,4));
  return 0;
}
int lua_trifill(lua_State *L) {
  trifill(BUFFER,WIDTH,HEIGHT,luaL_checknumber(L,1),luaL_checknumber(L,2),luaL_checknumber(L,3),luaL_checknumber(L,4),luaL_checknumber(L,5),luaL_checknumber(L,6),luaL_checknumber(L,7));
  return 0;
}
bool button_states[SDL_NUM_SCANCODES] = {false};
int lua_btn(lua_State *L) {
  const char* button_name = luaL_checkstring(L,1);
  SDL_Keycode keycode = SDL_GetKeyFromName(button_name);
  if (keycode!=SDLK_UNKNOWN) {
    SDL_Scancode scancode = SDL_GetScancodeFromKey(keycode);
    lua_pushboolean(L,button_states[scancode]);
  } else {
    lua_pushboolean(L,false);
  }
  return 1;
}
int lua_mouse(lua_State *L) {
  lua_pushinteger(L,mouse_x);
  lua_pushinteger(L,mouse_y);
  lua_pushinteger(L,mouse_btn);
  lua_pushinteger(L,wheel_x);
  lua_pushinteger(L,wheel_y);
  return 5;
}
int lua_save_png(lua_State *L) {
  RGB output[WIDTH*HEIGHT];
  for (int i=0;i<WIDTH*HEIGHT;++i) {
    output[i] = palette[BUFFER[i]];
  }
  char path[256];
  strcat(path,"drive/img/");
  strcat(path,luaL_checkstring(L,1));
  stbi_write_png(path,WIDTH,HEIGHT,3,output,WIDTH*sizeof(RGB));
}

int main() {
  if (SDL_Init(SDL_INIT_VIDEO)<0) {
    return 1;
  }
  SDL_Window* window = SDL_CreateWindow("PIX8C - Nxrix",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH*2.25,HEIGHT*2.25,SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
  if (!window) {
    SDL_Quit();
    return 1;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  SDL_Texture* texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING,WIDTH,HEIGHT);
  if (!texture) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  lua_register(L,"cls",lua_cls);
  lua_register(L,"pset",lua_pset);
  lua_register(L,"pget",lua_pget);
  lua_register(L,"print",lua_print);
  lua_register(L,"line",lua_line);
  lua_register(L,"rect",lua_rect);
  lua_register(L,"rectfill",lua_rectfill);
  lua_register(L,"circ",lua_circ);
  lua_register(L,"circfill",lua_circfill);
  lua_register(L,"trifill",lua_trifill);
  lua_register(L,"btn",lua_btn);
  lua_register(L,"mouse",lua_mouse);
  lua_register(L,"save_png",lua_save_png);

  int error = 0;
  char error_str[1024] = "";
  if (luaL_dofile(L,"drive/main.lua") != LUA_OK) {
    error = 1;
    snprintf(error_str+strlen(error_str),sizeof(error_str)-strlen(error_str),"error: %s\n",lua_tostring(L,-1));
    lua_pop(L,1);
  }
  lua_getglobal(L,"_init");
  if (lua_pcall(L,0,0,0)) {
    if (!error) {
      error = 1;
      snprintf(error_str+strlen(error_str),sizeof(error_str)-strlen(error_str),"_init error: %s\n",lua_tostring(L,-1));
    }
    lua_pop(L,1);
  }
  lua_getglobal(L,"_draw");
  int draw_ref = luaL_ref(L,LUA_REGISTRYINDEX);

  /*uint32_t lastTime = 0;
  uint32_t currentTime;
  int frameCount = 0;*/
  
  int running = 1;
  while (running) {
    int windowWidth,windowHeight;
    SDL_GetWindowSize(window,&windowWidth,&windowHeight);
    int scale = min(windowWidth/WIDTH,windowHeight/HEIGHT);
    int scaledWidth = WIDTH*scale;
    int scaledHeight = HEIGHT*scale;
    int windowX = (windowWidth-scaledWidth)/2;
    int windowY = (windowHeight-scaledHeight)/2;
    SDL_Event event;
    int eventScroll = 0;
    while (SDL_PollEvent(&event)) {
      if (event.type==SDL_QUIT) {
        running = 0;
      }
      bool press;
      if (event.type==SDL_KEYDOWN||event.type==SDL_KEYUP) {
        int state = (event.type==SDL_KEYDOWN)?1:0;
        button_states[event.key.keysym.scancode] = (event.type==SDL_KEYDOWN)?true:false;
        if (event.key.keysym.sym==SDLK_RETURN&&SDL_GetModState()&KMOD_ALT&&press==false) {
          if (fullscreen) {
            SDL_SetWindowFullscreen(window,0);
          } else {
            SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP);
          }
          fullscreen = !fullscreen;
          press = true;
        }
        if (event.type==SDL_KEYUP) {
          press = false;
        }
      }
      if (event.type==SDL_MOUSEBUTTONUP) {
        mouse_btn = 0;
      }
      if (event.type==SDL_MOUSEMOTION) {
        mouse_x = (event.motion.x-windowX)/scale;
        mouse_y = (event.motion.y-windowY)/scale;
      }
      if (event.type==SDL_MOUSEBUTTONDOWN) {
        if (event.button.button==SDL_BUTTON_LEFT) {
          mouse_btn = 1;
        } else if (event.button.button==SDL_BUTTON_RIGHT) {
          mouse_btn = 2;
        }
      }
      if (event.type==SDL_MOUSEWHEEL) {
        eventScroll = 1;
        wheel_x = event.wheel.x;
        wheel_y = event.wheel.y;
      }
    }
    if (!eventScroll) {
      wheel_x = 0;
      wheel_y = 0;
    }
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
    lua_rawgeti(L,LUA_REGISTRYINDEX,draw_ref);
    if (lua_pcall(L,0,0,0)) {
      if (!error) {
        error = 1;
        snprintf(error_str+strlen(error_str),sizeof(error_str)-strlen(error_str),"_draw error: %s\n",lua_tostring(L,-1));
      }
      cls(BUFFER,WIDTH,HEIGHT,0);
      print(BUFFER,WIDTH,HEIGHT,wrap_text(error_str,63),1,1,6);
      lua_pop(L,1);
    }
    for (int i=0;i<WIDTH*HEIGHT;++i) {
      BUFFERO[i] = palette[BUFFER[i]];
    }
    SDL_UpdateTexture(texture,NULL,BUFFERO,WIDTH*sizeof(RGB));
    SDL_Rect dstRect = {windowX,windowY,scaledWidth,scaledHeight};
    SDL_RenderCopy(renderer,texture,NULL,&dstRect);
    SDL_RenderPresent(renderer);

    /*frameCount++;
    currentTime = SDL_GetTicks();
    if (currentTime - lastTime >= 1000) {
      printf("FPS: %d\n",frameCount);
      frameCount = 0;
      lastTime = currentTime;
    }*/
  }
  lua_close(L);
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}