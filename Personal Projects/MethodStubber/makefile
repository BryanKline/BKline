all: stubber

stubber: MethodStubber.cpp StringNode.o
	g++ MethodStubber.cpp StringNode.o -o stubber

StringNode.o: StringNode.cpp
	g++ -c StringNode.cpp

clean:
	rm -f *.o stubber
