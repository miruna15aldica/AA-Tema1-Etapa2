CC = gcc
CFLAGS = -std=c99 -Wall
TARGETS = KMP.o RK.o TextGenerator.o

build: clean KMP.o RK.o TextGenerator.o
	$(CC) $(CFLAGS) -o test $(TARGETS) test.c 

KMP.o: KMP.c
	$(CC) $(CFLAGS) -c -o $@ $^

RK.o: RK.c
	$(CC) $(CFLAGS) -c -o $@ $^

TextGenerator.o: TextGenerator.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean: 
	rm -rf *.o test