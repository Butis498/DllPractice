# Run this for compiling the Dll #

gcc -c MyDll.c
gcc -shared -o MyDll.dll -Wl,--out-implib,libtstdll.a MyDll.o


## Compile main ##

gcc main.c

## Run ##

./a.exe