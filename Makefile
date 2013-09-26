default: build

build: snake.c
	gcc -o snake snake.c -lncurses

run: build
	./snake
