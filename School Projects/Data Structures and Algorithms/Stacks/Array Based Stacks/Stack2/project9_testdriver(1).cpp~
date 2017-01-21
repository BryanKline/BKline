#include "stackN.h"    // NEED TO CHANGE FOR ARRAY STACKS
#include <iostream>

bool NODE = true;      // CHANGE THIS TO FALSE WHEN TESTING ARRAY STACKS

using namespace std;

int main() {
	int size = 6;
	cout << "init stack of int of size " << size << endl;
	Stack intStack(size), copy, copy2;
	int selection;

	do{

		cout << "1. Push Data onto Stack" << endl;
		cout << "2. Check Assignment Operator" << endl;
		cout << "3. Check Copy Constructor" << endl;
		cout << "4. Check Compare Operator" << endl;
		cout << "5. Pop values off Stack" << endl;
		cout << "6. Push more values onto Stack" << endl;
		cout << "7. Clear Stack" << endl;
		cout << "8. Quit Program" << endl << endl;

		cout << "Please select an option: ";
		cin >> selection;

		cout << endl << endl << "****************************************" << endl;

		switch(selection)
		{
			case 1:

			char data;
			if(!intStack.empty()) {
				cout << "error in empty (says not empty when it is empty)" << endl;
			}
			// Pushing values		
			for(int i = 0; i < size; i++) {			
				cout << "push " << i << endl;
				// check push
				if(!intStack.push(i + '0')) {
					cout << "error in pushing" << endl;
				}
				// check full
				if(intStack.full() && i < size - 1 && !NODE) {
					cout << "error in full (says full when it is not full)" << endl;
				} else if (!intStack.full() && i == size - 1 && !NODE) {
					cout << "error in full (says not full when it is full" << endl;
				}
				// check empty
				if(intStack.empty() && !NODE) {
					cout << "error in empty (says empty when it is not empty)" << endl;
				}
			}

			// check overflow in array based only
			if(!NODE)
			{
				cout << "push -1 (overflow)" << endl;
				if(intStack.push(-1)) 
				{
					cout << "error detecting overflow" << endl;
				}
			}

			// check print
			cout << "Start print function, should have (5 4 3 2 1 0):" << endl;
			cout << intStack << endl;
			cout << endl << "End print function" << endl;

			break;

			case 2:


			// check assignment operator
			copy = copy2 = intStack;
			cout << "Start print function on copied stack:" << endl;
			cout << copy << endl;
			cout << endl << "End print function on copied stack" << endl;
			cout << "Start print function on the second copied stack:" << endl;
			cout << copy << endl;
			cout << endl << "End print function on the second copied stack" << endl;


			cout << endl << "The Stacks should match" << endl;

			break;


			case 3:
			{
				// check assignment operator
				Stack copy3 = intStack;
				cout << "Start print function on copied stack:" << endl;
				cout << intStack << endl;
				cout << endl << "End print function on copied stack" << endl;
				cout << "Start print function on the second copied stack:" << endl;
				cout << copy3 << endl;
				cout << endl << "End print function on the second copied stack" << endl;		

				cout << endl << "The Stacks should match" << endl;

			}





			break;


			case 4:

			cout << "Check the == operator (Should be EQUAL)" << endl;
			if(!(intStack == copy2)) {
				cout << "Error in == operator (says not equal when they are)" << endl;
			}

			cout << "Check the == operator (Should be NOT EQUAL)" << endl;
			copy2.pop(data);
			if(intStack == copy2) {
				cout << "Error in == operator (says equal when they are not)" << endl;
			}
			break;


			case 5:
			// Popping values
			for(int i = size - 1; i >= 0; i--) {	
				cout << "pop " << i << endl;
				// check pop
				if(intStack.pop(data)) {
					cout<< "popped " << data << endl;
				} else {
					cout << "error in popping" << endl;
				}
				// check full
				if(intStack.full() && !NODE) {
					cout << "error in full (says full when it is not full)" << endl;
				}
				// check empty
				if(intStack.empty() && i > 0 && !NODE) {
					cout << "error in empty (says empty when it is not empty)" << endl;
				} else if(!intStack.empty() && i == 0) {
					cout << "error in empty (says not empty when it is empty)" << endl;
				}
			}
			// check underflow in array based only
			if(!NODE)
			{
				cout << "pop (underflow)" << endl;
				if(intStack.pop(data)) {
					cout << "error detecting underflow" << endl;
				}	
			}



			break;






			case 6:
			// Pushing values		
			for(int i = 0; i < size/2; i++) {			
				cout << "push " << i << endl;
				// check push
				if(!intStack.push(i + '0')) {
					cout << "error in pushing" << endl;
				}
				// check full
				if(intStack.full() && i < size - 1 && !NODE) {
					cout << "error in full (says full when it is not full)" << endl;
				} else if (!intStack.full() && i == size - 1) {
					cout << "error in full (says not full when it is full" << endl;
				}
				// check empty
				if(intStack.empty() && !NODE) {
					cout << "error in empty (says empty when it is not empty)" << endl;
				}
			}

			cout << endl << "Should print out 2 1 0" << endl;
			cout << intStack << endl;


			break;


			case 7:
			cout << "clearing the stack" << endl;	
			if(!intStack.clear()) {
				cout << "error while clearing stack" << endl;
			}
			if(!intStack.empty()) {
				cout << "error, stack is not empty after clear" << endl;
			}
			cout << "Start print function:" << endl;
			cout << intStack << endl;
			cout << endl << "End print function" << endl;	
			break;
		}
		cout << endl << endl << "****************************************" << endl;

	}
	while(selection != 8);
}
