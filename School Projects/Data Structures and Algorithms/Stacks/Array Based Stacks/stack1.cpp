/**********************************************************************/
/*PROGRAM:      Project 9 (stack1.cpp)                                */
/*                                                                    */
/*AUTHOR:       Bryan Kline                                           */
/*                                                                    */				
/*DATE:         11/10/15                                              */
/*                                                                    */
/*REVISIONS:    1                                                     */
/*                                                                    */	
/*PURPOSE:      Implementation of array (top stay) based Stack class  */
/*              functions, overloaded operators, and friend function. */
/*                                                                    */
/**********************************************************************/

#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

//Stack (top stay) class implementation.

//Stack default constructor that takes in an int that will be the 
//size of the char array data.
Stack:: Stack(int size)
{
    //Memory dynamically allocated for data of size char.
    data = new char[size];

    //The data member max is set to the size of the array that
    //was passed in as a parameter and top and actual are set 
    //zero.
    max = size;
    top = 0;
    actual = 0;
}

//Stack copy constructor that takes in a Stack by reference and
//creates a Stack with the values as the one passed in as a 
//parameter.
Stack:: Stack(const Stack& stack)
{
    //The char pointer data is set to NULL and this dereferenced
    //is assigned the Stack passed in as a parameter.
    data = NULL;
    *this = stack;
}

//Stack destructor.
Stack:: ~Stack()
{
    //Stack data members are set to zero.
    max = 0;
    top = 0;
    actual = 0;

    //The memory allocated to the char pointer data is freed
    //and it's set to NULL.
    delete[] data;
    data = NULL;
}

//Stack function that takes in a char and pushes it onto the top of 
//the Stack and returns a bool corresponding to whether or not the push
//was successful.
bool Stack:: push(char letter)
{
    int i;

    //If statement that checks whether or not max an actual are equal,
    //if not then the array is not full and the letter is pushed on
    //and true is returned.
    if(actual != max)
    {
        //Counter controlled loop that starts at the element at actual
        //and goes backwards through the array and copies the element
        //at each index to the index ahead of it.
        for(i = (actual - 1); i > -1; i--)
        {
	        data[i + 1] = data[i];
        }	

        //The char letter passed into the function is assigned to
        //the the first index, top, and acutal is incremented.
        data[top] = letter;
        actual++;

        return true;
    }
    //If the array is full then false is returned.
    else
    {
        return false;
    }
}

//Stack function that takes in a char that it sets to the value of the letter
//popped off, pops off the top of the stack, and returns a bool corresponding
//to whether or not the function was successful in popping a char off the top
//of the Stack.
bool Stack:: pop(char &letter)
{
    int i;

    //If actual is not zero, if the array is not empty, then the top
    //of the Stack is popped off and true is returned.
    if(actual != 0)
    {	
        //The char passed in is set to the char at top in data.
        letter = data[top];

        //Counter controlled loop that goes through the array starting at
        //the index after top up to the element at index actual and copies
        //the char from each index to the one before it and actual 
        //is incremented.
        for(i = (top + 1); i < actual; i++)
        {
            data[i - 1] = data[i];
        }

        actual--;

        return true;
    }
    //If the array is empty then false is returned.
    else
    {
        return false;
    }
}

//Stack function that returns a bool corresponding to whether or not
//the Stack is empty.
bool Stack:: empty() const
{
    //If actual is zero, if the Stack is empty, then true is returned.
    if(actual == 0)
    {
        return true;
    }
    //If actual is not zero then the Stack is not empty and false
    //is returned.
    else 
    {
        return false;	
    }
}

//Stack function that returns a bool corresponding to wheter or not
//the Stack is full.
bool Stack:: full() const
{
    //If actual and max are equal then the Stack is full and true is returned.
    if(actual == max)
    {
        return true;
    }
    //If actual and max are not equal then the Stack is not full and false
    //is returned.
    else 
    {
        return false;	
    }
}

//Stack function that returns a bool corresponding to whether or not
//the Stack is cleared. 
bool Stack:: clear()
{
    //If acutal isn't already zero, if the Stack isn't empty, then
    //actual is set to zero and true is returned.
    if(actual != 0)
    {
        actual = 0;

        return true;
    }
    //If actual is already zero then false is returned.
    else
    {
        return false;
    }
}

//Overloaded Stack assignment operator that takes in a stack by reference
//and returns a stack by reference.
Stack& Stack:: operator = (const Stack& stack)
{
    int i;

    //If data is not NULL then the memory that data points to is freed.
    if(data != NULL)
    {
        delete[] data;
    }

    //The data member max is set to max of the stack passed in as parameter
    //and max is used as a size to dynamically allocate memory for a char
    //array that data points to. 
    max = stack.max;
    data = new char[max];

    //Counter controlled loop that goes through both char arrays, the one 
    //pointed to by data and that of the Stack passed in by as a parameter,
    //and the chars in the one passed in are copied into data.
    for(i = 0; i < stack.actual; i++)
    {
        data[i] = stack.data[i];
    }

    //The data members top and actual are set to values of the Stack passed in
    //as a parameter.
    top = stack.top;
    actual = stack.actual;

    //The Stack is returned by dereferencing this.
    return *this;	
}

//Overloaded Stack equality operator that takes in a Stack and returns a bool
//corresponding to whether or not the Stacks are equal.
bool Stack:: operator == (const Stack& stack) const
{
    int i = 0;

    //If either max or actual data members from either Stack are not
    //equal then false is returned.
    if((max != stack.max)||(actual != stack.actual))
    {
        return false;
    }

    //Event controlled loop that, while a counter, i, is less than actual
    //from either Stack, the elements are each index are checked for
    //equality.
    while((i < actual)&&(i <stack.actual))
    {
        //If the chars at the index i are not equal false is returned.
        if(data[i] != stack.data[i])
        {
            return false;
        }
        i++;
    }

    //True is returned.
    return true;
}


//Friend function implementation.

//Overloaded insertion operator function that takes in an ostream object
//and a Stack, both by reference, and returns an ostream object
//by reference and prints out the Stack to the screen.
ostream& operator << (ostream& out, const Stack& stack)
{
    int i;

    //If actual is not zero, if the Stack is not empty, then each element
    //in the char array is printed to the screen.
    if(stack.actual != 0)
    {
        //Counter controlled loop that goes from top to actual and
        //prints out each char in data.
        for(i = 0; i < stack.actual; i++)
        {	
            if(i == stack.top)
            {
                cout << "[" << stack.data[i] << "]" << endl;
            }
            else
            {
                cout << stack.data[i] << endl;
            }
        }
    }
    //If the Stack is empty then a new line is printed.
    else 
    {
        cout << endl;
    }	

    //The ostream object is returned.
    return out;
}
