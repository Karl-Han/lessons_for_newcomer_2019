all: binary_tree

binary_tree_main.o: binary_tree.h binary_tree_main.c
	$(CC) -g -c $^

binary_tree.o: binary_tree.h binary_tree.c
	$(CC) -g -c $^

binary_tree: binary_tree_main.o binary_tree.o
	$(CC) -g -o $@ $^

.PHONY: clean run
clean:
	rm *.o a.out *.h.gch binary_tree 

run: all
	./binary_tree
