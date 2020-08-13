all: run


run: Main.c HashTable.o Words.o TestUtils.o
	gcc -g Main.c HashTable.c Words.c TestUtils.c -o printAnagrams

test: Test.c HashTable.o Words.o TestUtils.o
	gcc -g Test.c HashTable.c Words.c TestUtils.c -o test

HashTable.o: HashTable.h HashTable.c
	gcc -c HashTable.c

Words.o: Words.c Words.h
	gcc -c Words.c

TestUtils.o: TestUtils.c TestUtils.h
	gcc -c TestUtils.c

clean:
	if [ -a printAnagrams ] ; \
	then \
		 rm printAnagrams ; \
	fi;
	if [ -a test ] ; \
	then \
		 rm test ; \
	fi;
	rm *.o