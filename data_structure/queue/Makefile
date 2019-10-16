all: queue_array queue_linkedlist

queue_main_array.o: queue_array.h queue_main_array.c
	$(CC) -g -c $^

queue_array.o: queue_array.h queue_array.c
	$(CC) -g -c $^

queue_array: queue_main_array.o queue_array.o
	$(CC) -g -o $@ $^


linked_list.o: linked_list.c linked_list.h
	$(CC) -g -c $^

queue_linkedlist.o: queue_linkedlist.h queue_linkedlist.c
	$(CC) -g -c $^

queue_main_linkedlist.o: queue_linkedlist.h queue_main_linkedlist.c
	$(CC) -g -c $^

queue_linkedlist: queue_main_linkedlist.o queue_linkedlist.o linked_list.o
	$(CC) -g -o $@ $^

.PHONY: clean run
clean:
	rm *.o a.out *.h.gch queue_array queue_linkedlist

run: all
	./queue_array
	./queue_linkedlist
