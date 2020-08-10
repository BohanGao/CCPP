all: run


run: run_gen_heapsort.c gen_heapsort.o heap_gen.o int_heapsort.o heap_int.o score.o int_helpers.o
	gcc -g run_gen_heapsort.c gen_heapsort.c gen_heap.c int_heapsort.c min_heap_int.c score.c int_helpers.c -o run_gen_heapsort

gen_heapsort.o: gen_heapsort.h gen_heapsort.c
	gcc -c gen_heapsort.c

heap_gen.o: gen_heap.c gen_heap.h
	gcc -c gen_heap.c

int_heapsort.o: int_heapsort.h int_heapsort.c
	gcc -c int_heapsort.c

heap_int.o: min_heap_int.c min_heap_int.h
	gcc -c min_heap_int.c

score.o: score.c score.h
	gcc -c score.c

int_helpers.o: int_helpers.c int_helpers.h
	gcc -c int_helpers.c

clean:
	rm *.o
	rm -fr *.dSYM
	rm run_gen_heapsort