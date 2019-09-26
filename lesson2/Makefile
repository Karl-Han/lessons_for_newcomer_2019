pointer: pointer.o pointer_main.o
	$(CC) -o $@ $^

bsearch: bsearch.o pointer.o
	$(CC) -o $@ $^

struct: struct.o
	$(CC) -o $@ $^

all: pointer bsearch

.PHONY: clean
clean:
	rm *.o a.out struct bsearch pointer
