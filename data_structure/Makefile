all: linked_list 

linked_list_main.o: linked_list.h linked_list_main.c
	$(CC) -g -c $^

linked_list.o: linked_list.h linked_list.c
	$(CC) -g -c $^

linked_list: linked_list_main.o linked_list.o
	$(CC) -g -o $@ $^

.PHONY: clean run
clean:
	rm *.o a.out *.h.gch linked_list 

run: all
	./linked_list
