#include <iostream>
#include "stack.h"

using namespace std;

int main()
{

	Stack stack1(3);
	Stack stack2;
	Stack stack3(stack1);

	int i;
	int choice;
	char letter;
	bool success; 

	success = false;
	
	choice = 0;
	
	while(choice != 9)
	{
		cout << endl;
		cout << "1. Push onto stack." << endl;
		cout << "2. Pop off of stack." << endl;
		cout << "3. Print out stack." << endl;
		cout << "4. Clear stack." << endl;
		cout << "5. Assign stack." << endl;
		cout << "6. Equate stack." << endl;
		cout << "7. Check if full." << endl;
		cout << "8. Check if empty." << endl;
		cout << "9. Exit." << endl;
		cout << "Enter a menu option:" << endl;
		cin >> choice;

		switch(choice)
		{
			case 1:
				cout << "Pushing onto stack." << endl;
				cout << "Enter a letter." << endl;
				cin >> letter;

				success = stack1.push(letter);

			break;

			case 2:
				cout << "Popping off of stack." << endl;
				success = stack1.pop(letter);
				cout << "The letter is now:" << endl;
				cout << letter << endl;

			break;

			case 3:
				cout << "Printing out stack." << endl;
				cout << stack1;
	
			break;

			case 4:
				cout << "Clearing stack." << endl;
				stack1.clear();
			break;

			case 5:
				cout << "Assigning stack." << endl;
				stack2 = stack1;
				cout << stack2;
			break;

			case 6:
				cout << "Equating stack." << endl;
	
				if(stack1 == stack2)
				{
					cout << "The stacks are equal." << endl;
				}
				else 
				{
					cout << "The stacks are not equal." << endl;
				}

				success = stack2.pop(letter);	

				if(stack1 == stack2)
				{
					cout << "The stacks are equal." << endl;
				}
				else 
				{
					cout << "The stacks are not equal." << endl;
				}

			break;

			case 7:
				cout << "Checking if full." << endl;
				
				if(stack1.full())
				{
					cout << "The stack is full." << endl;
				}
				else
				{
					cout << "The stack is not full." << endl;
				}

			break;

			case 8:
				cout << "Checking if empty." << endl;
	
				if(stack1.empty())
				{
					cout << "The stack is empty." << endl;
				}
				else
				{
					cout << "The stack is not empty." << endl;
				}			

				if(stack3.empty())
				{
					cout << "The stack is empty." << endl;
				}
				else
				{
					cout << "The stack is not empty." << endl;
				}	
	
			break;

			case 9:
				cout << "Exiting." << endl;
			break;

			default:
				cout << "Enter a valid choice" << endl;
		}
	
	cin.clear();
	cin.ignore();
	}


	return 0;
}
