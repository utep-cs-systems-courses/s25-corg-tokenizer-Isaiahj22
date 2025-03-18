

CFLAGS= -g -O3

all: uimain

tokenizer.o: tokenizer.h
history.o: history.h

uimain.o: uimain.c history.h tokenizer.h



uimain: uimain.o history.o tokenizer.o
	cc -o uimain uimain.o history.o tokenizer.o $(CFLAGS) 

# Compilation rules
history.o: history.c
	cc -c -o history.o history.c $(CFLAGS)

tokenizer.o: tokenizer.c
	cc -c -o tokenizer.o tokenizer.c $(CFLAGS)

uimain.o: uimain.c
	cc -c -o uimain.o uimain.c $(CFLAGS)

# Clean rule
clean:
	rm -f history.o tokenizer.o uimain.o uimain
