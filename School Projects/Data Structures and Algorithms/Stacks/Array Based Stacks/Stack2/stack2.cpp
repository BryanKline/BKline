/**********************************************************************/
/*PROGRAM:      Project 9 (stack2.cpp)                                */
/*                                                                    */
/*AUTHOR:       Bryan Kline                                           */
/*                                                                    */				
/*DATE:         11/10/15                                              */
/*                                                                    */
/*REVISIONS:    1                                                     */
/*                                                                    */	
/*PURPOSE:      Implementation of array (top move) based Stack class  */
/*              functions, overloaded operators, and friend function. */
/*                                                                    */
/**********************************************************************/

#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

//Stack (top move) class implementation.

//Stack default constructor that takes in an int that will be the 
//size of the char array data.
Stack:: Stack(int size)
{
    //Memory dynamically allocated for data of size char.
    data = new char[size];

    //The data member max is set to the size of the array that
    //was passed in as a parameter and top is set to -1 so that
    //when top is incremented the first time it will be at zero.
    max = size;
    top = -1;
}

//Stack copy constructor that takes in a Stack by reference and
//creates a Stack with the values as the one passed in as a 
//parameter.
Stack:: Stack(const Stack& stack)
{
    //The char pointer data is set to NULL as the overloaded assignment
    //operator checks if data is NULL before deallocating memory before
    //allocating new memory.  Then the overloaded assignment operator
    //is used to copy in the values from the Stack passed in as a 
    //parameter to this dereferenced.
    data = NULL;
    *this = stack;
}

//Stack destructor.
Stack:: ~Stack()
{
    //Data members max and top set to -1.
    max = 0;
    top = -1;

    //The memory dynamically allocated for data is freed and
    //data is set to NULL.
    delete[] data;
    data = NULL;
}

//Stack function that takes in a char and pushes it onto the top of 
//the Stack and returns a bool corresponding to whether or not the push
//was successful.
bool Stack:: push(char letter)
{
    //If top is less than max minus one then top is incremented and the char
    //at the index indicated with offset notation at top is assigned the char
    //passed in as a parameter and true is returned. 
    if(top < (max - 1))
    {
        top++;
        data[top] = letter;

        return true;
    }
    //If top is at the end of the array then false is returned, indicating that
    //the push was not successful.
    else 
    {
        return false;
    }
}

//Stack function that takes in a char by reference that it sets to the
//value of the letter popped off, pops off the char at the top of the stack
//and returns a bool corresponding to whether or not the pop was successful.
bool Stack:: pop(char &letter)
{
    //If top is greater than -1 then the array holds some
    //values and then top is decremented and true is returned
    //indicating the pop was successful.
    if(top > -1)
    {

        //The char passed in is set to the char at top in data.
        letter = data[top];

        top--;

        return true;
    }

    //False is returned if the above statement was entered and no
    //value could be popped off the stack.
    return false;
}

//Stack function that returns a bool corresponding to whether or not
//the Stack is empty.
bool Stack:: empty() const
{
    //If top is equal to -1 then the array has no values and true
    //is returned.
    if(top == -1)
    {
        return true;
    }
    //If top is not equal to -1 then the array is not empty and false
    //is returned.
    else 
    {
        return false;	
    }
}

//Stack function that returns a bool corresponding to whether or not
//the Stack is full.
bool Stack:: full() const
{
    //If top is equal to max minus one, if it's at the end of the array,
    //then the Stack is full and true is returned.
    if(top == (max - 1))
    {
        return true;
    }
    //If top is not equal to max minus one then the Stack is not full
    //and false is returned.
    else 
    {
        return false;	
    }
}

//Stack function that returns a bool corresponding to whether or not the
//Stack was successfully cleared.
bool Stack:: clear()
{
    //If top is not already -1 then the Stack contains values, top is set
    //to -1, and true is returned.
    if(top != -1)
    {
        top = -1;
        return true;
    }
    //If top is already -1 then the Stack has no values and false is returned.
    else
    {
        return false;
    }
}

//Overloaded Stack assignment operator that takes in a Stack and returns
//a Stack, both by reference.
Stack& Stack:: operator = (const Stack& stack)
{
    int i;

    //If data is not NULL then the memory allocated for the char array is freed.
    if(data != NULL)
    {
        delete[] data;
    }

    //The data member max is set to max of the Stack passed in as a parameter
    //and memory is allocated for data of that size.
    max = stack.max;
    data = new char[max];

    //Counter controlled loop that goes through each char array
    //up to top of the Stack passed in and the chars in that array
    //are copied into the char array pointed to by data.
    for(i = 0; i < max; i++)
    {
        data[i] = stack.data[i];
    }

    //The data member top is set to the value of top of the Stack passed in
    //as a parameter.
    top = stack.top;

    return *this;	
}

//Overloaded Stack equality operator that takes in a Stack by reference
//and returns a bool corresponding to whether or not the Stacks are equal.
bool Stack:: operator == (const Stack& stack) const
{
    int i;

    i = 0;

    //If either max or top from both Stacks are not equal then false is
    //returned.  
    if((max != stack.max)||(top != stack.top))
    {
        return false;
    }

    //Event controlled loop that, while a counter, i, is less than top from
    //each Stack, the chars at that index of each Stack are compared and if
    //they are not equal then false is returned.
    while((i < top)&&(i <stack.top))
    {
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

//Overloaded insertion operator function that takes in an ostream
//object and a Stack, both by reference, and returns an ostream
//object by reference and prints out the Stack to the screen.
ostream& operator << (ostream& out, const Stack& stack)
{
    int i;

    //If top is not -1, if the Stack is not empty, the values in Stack
    //are printed to the screen.
    if(stack.top != -1)
    {
        //Counter controlled loop that starts at top and goes back through 
        //data and prints each char in the array to the screen.
        for(i = (stack.top); i > -1; i--)
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
    //If the Stack is empty then a new line printed to the screen.
    else 
    {
        cout << endl;
    }	

    //The ostream object is returned.
    return out;
}
