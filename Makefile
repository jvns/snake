default: build

build: snake.c
	gcc -o snake main.c snake.c -lncurses

run: build
	./snake

tests: src/snake.c src/snake.h test/test.ts
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
	checkmk test/test.ts > test/test.c
	gcc -o run_tests src/snake.c src/snake.h test/test.c -lncurses -lcheck
	./run_tests

clean:
	rm snake run_tests
