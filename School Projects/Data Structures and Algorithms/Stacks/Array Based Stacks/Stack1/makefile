all: project9

project9: project9.cpp stack1.o
	g++ project9.cpp stack1.o -o project9

stack3.o: stack1.cpp
	g++ -c stack1.cpp

clean:
	rm -f *.o project9
