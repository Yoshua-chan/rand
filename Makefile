CC = gcc
rand: main.c
	gcc main.c -o ./rand

install: rand
	mv ./rand /usr/local/bin/rand
