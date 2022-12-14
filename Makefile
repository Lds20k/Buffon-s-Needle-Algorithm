# Build bcc fdisk

std=-std=c11

debug: fdisk-bcc-debug

fdisk-bcc-debug: bin/main.o
	gcc $(std) -O0 -o bin/fdisk-bcc bin/main.o -g -W -Wall -lm -pedantic

bin/main.o: main.c bin
	gcc $(std) -O0 -o bin/main.o main.c -g -c -W -Wall -lm -pedantic

bin:
	mkdir bin

clean:
	rm -rf bin