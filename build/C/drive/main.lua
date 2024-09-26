--[[

Pix-8 C/Lua v9 alpha - Nxrix

alt + enter for fullscreen

api:

  cls(c)
  pset(x,y,c)
  pget(x,y)
  print(text,x,y,c)
  line(x0,y0,x1,y1,c)
  rect(x0,y0,x1,y1,c)
  rectfill(x0,y0,x1,y1,c)
  circ(x,y,r,c)
  circfill(x,y,r,c)
  btn(name) -- "z","0","left ctrl","return",...
  x,y,b,sx,sy = mouse()
  save_png(name)

]]

function printo(txt,x,y,a,b)
  print(txt,x-1,y-1,b)
  print(txt,x  ,y-1,b)
  print(txt,x+1,y-1,b)
  print(txt,x-1,y  ,b)
  print(txt,x+1,y  ,b)
  print(txt,x-1,y+1,b)
  print(txt,x  ,y+1,b)
  print(txt,x+1,y+1,b)
  print(txt,x,y,a)
end

function _init()
  b4 = {
    { 0, 8, 2, 10},
    {12, 4, 14, 6},
    { 3, 11, 1, 9},
    {15, 7, 13, 5}
  };
  b8 = {
    { 0, 32,  8, 40,  2, 34, 10, 42},
    {48, 16, 56, 24, 50, 18, 58, 26},
    {12, 44,  4, 36, 14, 46,  6, 38},
    {60, 28, 52, 20, 62, 30, 54, 22},
    { 3, 35, 11, 43,  1, 33,  9, 41},
    {51, 19, 59, 27, 49, 17, 57, 25},
    {15, 47,  7, 39, 13, 45,  5, 37},
    {63, 31, 55, 23, 61, 29, 53, 21}
  };
  t = 1
  max_iter=128
  w = 256
  h = 192
  a = w/h
  w1 = w-1
  h1 = h-1
  w2 = w/2
  h2 = h/2
  scx = 2/w*a
  scy = 2/h
  ox,oy,ox1,oy1,msx,msy,os = 0,0,0,0,0,0,1/2
end

function mandelbrot(c_re,c_im,max_iter)
  local z_re,z_im = 0,0
  local abs_z_sq = 0
  for n = 0, max_iter - 1 do
    abs_z_sq = z_re * z_re + z_im * z_im
    if abs_z_sq > 4 then
      return n
    end
    local temp_re = z_re * z_re - z_im * z_im + c_re
    z_im = 2 * z_re * z_im + c_im
    z_re = temp_re
  end
  return max_iter
end

function tr(x,y)
  return (x-ox)/2/a*os*w+w2,(y-oy)/2*os*h+h2
end

function _draw()
  local c_re,c_im
  cls(0)
  for x=0,w1,2 do
    c_re=(x*scx-a)/os+ox
    for y=0,h1,2 do
      c_im = (y*scy-1)/os+oy
      local n = mandelbrot(c_re,c_im,max_iter)
      local c = (n==max_iter) and 0 or (n+1)
      --c = (c+b4[(x&3)+1][(y&3)+1]>>4)%4
      --pset(x,y,c)
      rectfill(x,y,x+1,y+1,c)
    end
  end
  printo("+",w2-1,h2-2,3,0)
  --[[if btn("left") then ox=ox-1/os*scx*2 end
  if btn("right") then ox=ox+1/os*scx*2 end
  if btn("up") then oy=oy-1/os*scy*2 end
  if btn("down") then oy=oy+1/os*scy*2 end
  if btn("z") then os=os*2 end
  if btn("x") then os=os/2 end]]
  if t==1 then save_png("mandelbrot.png") end
  t = t + 1
  local mx,my,mb,mh,mv = mouse()
  if mb>0 then
		if click_started==false then
			msx,msy=mx,my
			click_started=true
		end
    if mb==1 then
      ox = ox1+(msx-mx)/w/os*2*a
      oy = oy1+(msy-my)/h/os*2
    end
  else
    ox1,oy1 = ox,oy
    click_started=false
  end
  if mv ~= 0 then
    os = os*2^mv
    --[[if mv>0 then
      ox = ox+(mx-w2)/w/os*2*a
      oy = oy+(my-h2)/h/os*2
    else
      ox = ox-(mx-w2)/w/os*a
      oy = oy-(my-h2)/h/os
    end]]
  end
  printo("hello world!",2,2,3,0)
  printo("use mouse to move and zoom",2,9,3,0)
  printo("colors:",2,151,3,0)
  rect(1,157,66,190,0);
  for i=0,7 do
    for j=0,3 do 
      s = 8
      x = i*s+2
      y = j*s+158
      rectfill(x,y,x+s-1,y+s-1,i*4+j)
    end
  end
  --trifill(64,64,255,0,0,191,0)
end
