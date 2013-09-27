default: build

build: src/snake.c src/main.c
	gcc -o snake src/main.c src/snake.c -lncurses

run: build
	./snake

tests: src/snake.c src/snake.h test/test.ts
	checkmk test/test.ts > test/test.c
	gcc -o run_tests src/snake.c src/snake.h test/test.c -lncurses -lcheck
	./run_tests

clean:
	rm snake run_tests
