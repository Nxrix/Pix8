call icon.bat
REM -funroll-loops
gcc -g src/PIX8C.c src/data/rc.o -o build/C/PIX8C -lSDL2main -lSDL2 -llua -mwindows -O3
cd build
cd C
PIX8C.exe