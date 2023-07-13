all: loaded.so test

loaded.so: loaded.c
	gcc -shared -o loaded.so -fPIC loaded.c

test: test.c
	gcc -o test test.c -ldl

clean:
	rm -f loaded.so test

run: all
	./test
