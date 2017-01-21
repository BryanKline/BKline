all: project9

project9: project9.cpp stack2.o
	g++ project9.cpp stack2.o -o project9

stack3.o: stack2.cpp
	g++ -c stack2.cpp

clean:
	rm -f *.o project9
