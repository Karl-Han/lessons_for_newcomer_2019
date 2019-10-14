all: linked_list linked_list_complex

linked_list_main.o: linked_list.h linked_list_main.c
	$(CC) -g -c $^

linked_list_main_complex.o:  linked_list_main_complex.c linked_list_complex.h
	$(CC) -g -c $^

linked_list_complex.o: linked_list_complex.h linked_list_complex.c
	$(CC) -g -c $^

linked_list.o: linked_list.h linked_list.c
	$(CC) -g -c $^

linked_list_complex:  linked_list_main_complex.o linked_list_complex.o
	$(CC) -g -o $@ $^

linked_list: linked_list_main.o linked_list.o
	$(CC) -g -o $@ $^

.PHONY: clean run
clean:
	rm *.o a.out *.h.gch linked_list linked_list_complex

run: all
	./linked_list
