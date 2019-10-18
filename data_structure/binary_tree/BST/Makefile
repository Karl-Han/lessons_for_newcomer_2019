all: binary_search_tree

main.o: binary_search_tree.h main.c
	$(CC) -g -c $^

binary_search_tree.o: binary_search_tree.h binary_search_tree.c
	$(CC) -g -c $^

binary_search_tree: main.o binary_search_tree.o
	$(CC) -g -o $@ $^

.PHONY: clean run
clean:
	rm *.o a.out *.h.gch binary_search_tree 

run: all
	./binary_search_tree
