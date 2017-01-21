/**********************************************************************/
/*PROGRAM:      Project 9 (stack3.cpp)                                */
/*                                                                    */
/*AUTHOR:       Bryan Kline                                           */
/*                                                                    */				
/*DATE:         11/10/15                                              */
/*                                                                    */
/*REVISIONS:    1                                                     */
/*                                                                    */	
/*PURPOSE:      Implementation of Node based Stack class functions    */
/*              overloaded operators, and friend function.            */
/*                                                                    */
/**********************************************************************/

#include <iostream>
#include <cstdlib>
#include "stackN.h"

using namespace std;

//Node class implementation.

//Node default constructor that takes in a char and a Node pointer
//as parameters.
Node:: Node(char letter, Node* nextPtr)
{
    //The Node data members are assigned the values passed in
    //as parameters.
    next = nextPtr;
    data = letter;	
}

//Stack class implementation.

//Stack default constructor that takes in an int and ignores it.
Stack:: Stack(int ignore)
{
    //The data member Node pointer is set to NULL. 
    top = NULL;
}

//Stack copy constructor.
Stack:: Stack(const Stack& stack)
{
    //The overloaded Stack assignment operator is used on this dereferenced.
    *this = stack;
}

//Stak destructor.
Stack:: ~Stack()
{
    Node* temp1;
    Node* temp2;
    temp1 = top;
    temp2 = top;

    //Event controlled loop that, while the node pointer temp1 isn't
    //NULL, sets temp1 equal to the current Node's next data member so
    //it's pointing to the next Node, deletes temp2, which is pointing
    //at the current Node, then sets temp2 to temp1 so it now points at
    //the next Node.
    while(temp1 != NULL)
    {
        temp1 = temp1->next;
        delete temp2;
        temp2 = temp1;
    }

    //The Stack data member top is set to NULL.
    top = NULL;
}

//Stack function that takes in a char and creates a Node with that value and
//pushes it onto the top of the Stack and returns a bool corresponding to 
//whether or not it was successful.
bool Stack:: push(char letter)
{
    Node* temp;

    //If top is not NULL then memory for a Node is dynamically allocated and
    // the char passed into push is passed into the Node's default constructor
    //along with top for next, top is assigned to temp, temp is set to NULL
    //and true is returned indicating that the process was successful.
    if(top != NULL)
    {
        temp = new Node(letter, top);
        top = temp;
        temp = NULL;

        return true;
    }
    //If top is NULL, meaning the Stack does not yet hold any Nodes, then
    //memory for a new Node is dynamically allocated with the char letter
    //and NULL passed into the default constructor and true is returned.
    else
    {
        top = new Node(letter, NULL);

        return true;
    }

    //False is returned if neither above statement is executed.
    return false;
}

//Stack function that takes in a char and sets assigns it the value of the char
//at data of the top Node, pops off the Node at the top of the Stack and returns
//a bool corresponding to whether or not it was successful.
bool Stack:: pop(char& letter)
{
    Node* temp;
    temp = top;	

    //If temp is not NULL then letter is set to the char in data of the top Node,
    //top is set to the next Node's address, the previous Node is deleted, temp
    //is set to NULL, and true is returned indicating that the Node was popped
    //off successfully.
    if(temp != NULL)
    {
        letter = top->data;	
        top = temp->next;
        delete temp;
        temp = NULL;

        return true;
    }
    //If temp is NULL, meaning there are no Nodes in the Stack,
    //then false is returned. 
    else
    {
        return false;
    }
}

//Stack function that returns a bool corresponding to whether or not the 
//Stack is empty.
bool Stack:: empty() const
{
    //If top is NULL then the Stack is empty and true is returned.
    if(top == NULL)
    {
        return true;
    }

    //If top is not NULL then the Stack contains at least one Node
    //and so false is returned.
    return false;
}

//Stack function that returns a bool corresponding to whether or not the 
//Stack is full.
bool Stack:: full() const
{
    //As Node based Stacks can never be full, false is returned.
    return false;
}

//Stack function that that returns a bool corresponding to whether or not
//the Stack was successfully cleared.
bool Stack:: clear()
{
    Node* temp1;
    Node* temp2;
    temp1 = top;
    temp2 = top;

    //If top is NULL, if the Stack is empty, then false is returned.
    if(top == NULL)
    {
        return false;
    }

    //Event controlled loop that, while temp1 which initially points at top, is
    //not pointing to NULL, sets temp1 to its pointer next, so it's pointing to
    //the next Node, deletes temp2, which initially is pointing at top, and then
    //sets temp2 to temp1;
    while(temp1 != NULL)
    {
        temp1 = temp1->next;
        delete temp2;
        temp2 = temp1;
    }

    //Top is set to NULL and true is returned.
    top = NULL;

    return true;
}

//Overloaded Stack assignment operator that takes a Stack and returns
//a Stack, both by reference.
Stack& Stack:: operator = (const Stack& stack)
{
    bool success;	

    //The clear function of this is used to delete all the Nodes
    //in the Stack.
    success = this->clear();

    Node* temp1;
    Node* temp2;

    temp1 = stack.top;
    temp2 = NULL;

    //If the Stack passed in as a parameter is not empty then it's values
    //will be assigned to "this".
    if(stack.top != NULL)
    {
        //If the Node pointer next of the Node pointed to by top of the
        //Stacked passed in is NULL then it means there is only one
        //Node in the Stack and memory is dynamically allocated to top
        //with the char in data of temp1, which is top of the Stack passed in, 
        //and NULL passed into the Node constructor.
        if((stack.top)->next == NULL)
        {
            top = new Node(temp1->data, NULL);
        }
        //If the Node pointer next is not NULL then there are more than one
        //Node in the Stack and an event controlled loop goes through the
        //Nodes in the Stack while next is not NULL and creates memory for 
        //Nodes and passes in data and NULL into the constructor of each.
        else
        {	
            //Event controlled loop that while next of temp1 is not NULL
            //Nodes are created. 
            while(temp1->next != NULL)	
            {
                //If top is NULL, if this is the first Node to be created, then 
                //memory is allocated for top with data from temp1, which is the
                //top of the Stack passed in, and NULL passed into the constructor.
                //Then, temp1 is set to the next Node by setting it equal to what
                //its next pointer points to, and temp2 is set to top.
                if(top == NULL)
                {
                    top = new Node(temp1->data, NULL);
                    temp1 = temp1->next;
                    temp2 = top;
                }
                //If top is not NULL then this is not the first Node to be created,
                //and so what next of temp2 points to has memory allocated to it with 
                //data from temp1 and NULL passed into the constructor, and temp1 and 
                //temp2 are set to point to the Nodes their next pointers point to.
                else
                {
                    temp2->next = new Node(temp1->data, NULL);
                    temp2 = temp2->next;
                    temp1 = temp1->next;
                }
            }

            //Once the next pointer of temp1 points to NULL it's at the next to last
            //Node in the Stack passed in and so next of temp2 needs to have memory
            //allocated to it with data from temp1 and NULL passed into the constructor
            //to create the last Node.
            temp2->next = new Node(temp1->data, NULL);
        }
    }

    //The Stack is returned with this dereferenced.
    return *this;
}

//Overloaded Stack equality operator that takes in a Stack by reference
//and returns a bool corresponding to whether or not the Stacks are 
//equal.
bool Stack:: operator == (const Stack& stack) const
{
    Node* temp1;
    Node* temp2;
    bool match;

    temp1 = top;
    temp2 = stack.top;

    match = false;

    //If top from both Stacks is NULL then they are equal and true is returned.	
    if((top == NULL)&&(stack.top == NULL))
    {
        return true;
    }

    //If top is not NULL, if the Stack is not empty, then Node pointers temp1
    //and temp2 go through the Nodes of each stack and the chars in data
    //of each Stack are compared and if they are different at any point
    //false is returned, if they are equal then match is set to true.
    if(top != NULL)
    {
        //If the chars in data from each Stack are equal then the bool
        //match is set to true.
        if(temp1->data == temp2->data)
        {
            match = true;
        }

        //Counter controlled loop that, while the pointer next of each
        //Stack is not NULL, goes through the Stacks and checks the
        //chars in each char array.
        while((temp1->next != NULL)&&(temp2->next != NULL))
        {
            //If the chars in data from each Stack are equal then the bool
            //match is set to true.
            if(temp1->data == temp2->data)
            {
                match = true;
            }
            //If the are not true then false is returned.
            else 
            {
                return false;
            }

            //The Node pointers temp1 and temp2 are set equal to their Node
            //pointer next to move to the next Node in each Stack.	
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        //If either Node pointer next is not pointing to NULL, meaning
        //one is not at the end of the Stack, then false is returned.
        if((temp1->next != NULL)&&(temp2->next != NULL))
        {
            return false;
        }
    }

    //The bool match is returned.
    return match;
}

//Friend function implementaion.

//Overloaded insertion operator function that takes in an ostream 
//object by reference and a Stack object by reference and returns
//an ostream object by reference.
ostream& operator << (ostream& out, const Stack& stack)
{
    Node* temp;

    temp = stack.top;

    //If top is not NULL then while temp is not NULL then the
    //Node member data is printed to the screen and temp is 
    //set to the address of the next Node.
    if(stack.top != NULL)
    {
        while(temp != NULL)
        {
            if(temp == (stack.top))
            {
                cout << "[" << temp->data << "]" << endl;
                temp = temp->next;
            }
            else
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
    //If top is NULL the a new line is printed.
    else
    {
        cout << endl;
    }

    //The ostream object is returned.
    return out;
}
