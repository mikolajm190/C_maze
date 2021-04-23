IDIR=../include
CC=gcc
CFLAGS=-Wall -I$(IDIR)

ODIR=obj

LIBS=-lncurses

_DEPS=displayAndInput.h mazeGeneration.h macros.h player.h AIplayer.h mazeUtils.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=displayAndInput.o mazeGeneration.o maze.o player.o AIplayer.o mazeUtils.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -g -o $@ $< $(CFLAGS)

mazemake.game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
