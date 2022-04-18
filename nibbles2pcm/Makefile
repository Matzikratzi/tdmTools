CC=gcc
CFLAGS=-I.
DEPS = #hellomake.h
OBJ = nibbles2pcm.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

nibbles2pcm: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

all: nibbles2pcm
	./nibbles2pcm ~/440-4400-0405-2.bin > 440-2.txt
