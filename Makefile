CC=gcc
CFLAGS=-I.

writeflash: main.o
     $(CC) -o writeflash main.o