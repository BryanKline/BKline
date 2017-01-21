all: main

main: main.cpp TextTree.o
	g++ main.cpp TextTree.o -o main

TextTree.o: TextTree.cpp
	g++ -c TextTree.cpp

clean:
	rm -f *.o main
