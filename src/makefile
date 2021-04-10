IDIR=../include
CC=gcc
CFLAGS=-Wall -I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lncurses

_DEPS=displayAndInput.h mazeGeneration.h macros.h player.h AIplayer.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=displayAndInput.o mazeGeneration.o maze.o player.o AIplayer.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -g -o $@ $< $(CFLAGS)

mazemake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
