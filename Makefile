.PHONY: all

all: ringbuf main
CC:=gcc

main: bytemincer.c
	${CC} ringbuf.o bytemincer.c -o bytemincer
ringbuf: ringbuf.c
	${CC} ringbuf.c -c 
clean:
	rm -rvf *.o 