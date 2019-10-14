all: stack_array stack_linkedlist

stack_main_array.o: stack_array.h stack_main_array.c
	$(CC) -g -c $^

stack_array.o: stack_array.h stack_array.c
	$(CC) -g -c $^

stack_array: stack_main_array.o stack_array.o
	$(CC) -g -o $@ $^


linked_list.o: linked_list.c linked_list.h
	$(CC) -g -c $^

stack_linkedlist.o: stack_linkedlist.h stack_linkedlist.c
	$(CC) -g -c $^

stack_main_linkedlist.o: stack_linkedlist.h stack_main_linkedlist.c
	$(CC) -g -c $^

stack_linkedlist: stack_main_linkedlist.o stack_linkedlist.o linked_list.o
	$(CC) -g -o $@ $^

.PHONY: clean run
clean:
	rm *.o a.out *.h.gch stack_array stack_linkedlist

run: all
	./stack_array
	./stack_linkedlist
