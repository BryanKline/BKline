
// Bryan Kline
// Feb. 2016
// StringNode and StringList class implementations (StringNode.cpp)

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "StringNode.h"

using namespace std;

//StringNode class methods
//StringNodes hold each a string and an index corresponding to their position in the list

//StringNode parameterized constructor
StringNode:: StringNode(char* string, int number, int section, StringNode *nextNode)
{
    int length = strlen(string) + 1;

    //the data members set to the values of the parameters passed in
    nodeString = new char[length];
    strcpy(nodeString, string);
    index = number;
    currentSection = section;    
    next = nextNode;
}

//StringNode destructor
StringNode:: ~StringNode()
{

    //nodeString is deleted and pointers set to NULL
    if(nodeString != NULL)
    {
        delete[] nodeString;
        nodeString = NULL;
    }
   
    next = NULL;
}

//StringList class methods
//StringList class is a linked list of StringNodes

//StringListdefault constructor
StringList:: StringList()
{
    //all data members set to default values
    size = 0;
    sections = 0;
    currentIndex = 0;
    head = NULL;
    current = NULL;
    tail = NULL;
}

//StringList destructor
StringList:: ~StringList()
{
    StringNode *temp;
    temp = current = head;

    //moves through the list and deletes each node
    while(current != NULL)
    {
        current = current->next;
        delete temp;
        temp = current;
    }

    //data member pointer set to NULL
    head = NULL;
    current = NULL;
    tail = NULL;
}

//StringList method to check if the list is empty
//returns bool corresponding to whether or not the list is empty
bool StringList:: isEmpty()
{
    //if head is NULL and size is zero then it's empty
    if(head == NULL && size == 0)
    {
        return true;
    }

    return false;
}

//StringList method to add a StringNode to the list
//returns bool corresponding to success of add operation
bool StringList:: addString(char* string, int number, int section, StringNode *nextNode, bool newSection)
{
    StringNode* temp;    

    //if the list is empty then a new node is created at head and data members
    //are updated
    if(isEmpty())
    {
        head = new StringNode(string, number, section, nextNode);
        tail = current = head;
        size++;
    }    
    //if the list is not empty then a node is added to the tail and data
    //members are updated
    else
    {
        temp = tail;
        tail->next = new StringNode(string, number, section, nextNode);
        tail = tail->next;
        size++;
        
        if(newSection)
        {
            sections++;
        }
    }

    //if there was no memory to create a new node false is returned
    if(tail == NULL)
    {
        tail = temp;    
        return false;    
    }    

    //if there was memory then true is returned
    return true;
}

//StringList method to remove a StringNode from the list at a given index
//returns bool corresponding to success of remove operation
bool StringList:: removeString(int index)
{
    int indexCounter;
    StringNode *temp;
    
    //if index is valid then the node at that index is removed by navigating to
    //that node and deleting it and true is returned
    if(index >= 0 && index < size)
    {
        if(index == 0)
        {
            temp = head;
            head = head->next;
            delete temp;
            current = head;
        }    
        else
        {
            current = head;

            for(indexCounter = 0; indexCounter < index - 1; indexCounter++)
            {
                current = current->next;            
            }

            temp = current;
            current = (current->next)->next;
            delete temp->next;
            temp->next = current;
            
            if(current == NULL)
            {
                current = temp;
            }       
        }

        setIndices();
        currentIndex = index;
        size--;

        return true;
    }

    //if the index is not valid then false is returned
    return false;
}

//StringList method to change the value of the string at a given index in the list
//returns bool corresponding to success of operation of changing the string 
bool StringList:: setString(int index, char* string)
{
    int indexCounter, length;

    //if the list is not empty and the index parameter is valid then
    //the node at that index is navigated to, if it's not NULL then 
    //it's deleted, and then the string at the node is set to the one 
    //passed in as a parameter and true is returned
    if(!isEmpty() && index >= 0 && index < size)
    {
        current = head;

        for(indexCounter = 0; indexCounter < index; indexCounter++)
        {
            current = current->next;            
        }

        if(current->nodeString != NULL)
        {
            delete[] current->nodeString;
        }
        
        length = strlen(string) + 1;
        current->nodeString = new char[length];
        strcpy(current->nodeString, string);

        return true;
    }

    //if the list is empty or the index was invalid false is returned
    return false;
}

//StringList method to check if at the end of the list
//returns a bool corresponding to whether or not a given index is the last
bool StringList:: atEnd(int index)
{
    //if the list is not empty and the index parameter is valid then
    //index is checked against size and true is returned
    if(!isEmpty() && index >= 0 && index < size)
    {
        if(index == size - 1)
        {
            return true;
        }
    }

    //if the list is empty or index is not valid then false is returned
    return false;
}

//StringList method to get the size of the list
//returns int corresponding to the total size of the list
int StringList:: getSize()
{
    return size;
}

//StringList method to get a string from a node at a given index
//returns the string at the specified index
char* StringList:: getString(int index)
{
    //if the list is not empty and the index parameter is valid then
    //the node at that index is navigated to and a pointer to its
    //string is returned and true is returned
    if(!isEmpty() && index >= 0 && index < size)
    {
        current = head;

        for(currentIndex = 0; currentIndex < index; currentIndex++)
        {
            current = current->next;            
        }

        return current->nodeString;
    }

    //if the list is empty or the index was invalid NULL is returned
    return NULL;
}

//StringList method to print the list to the screen
//void
void StringList:: diagnosticPrint()
{
    int index;

    //if the list is not empty then the total size is printed and then
    //each node's index and string is printed to the screen
    if(!isEmpty())
    {
        current = head;

        cout << "List size: " << size << endl;
        for(index = 0; index < size; index++)
        {
            cout << current->index << endl;
            cout << current->nodeString << endl;
            current = current->next;            
        }

        current = head;
    }
    //if the list is empty then a message is printed to the screen
    else
    {
        cout << "The list is empty" << endl;
    }
}

//StringList method to move through the list and update the indices
//void
void StringList:: setIndices()
{
    int indexCounter = 0;
    StringNode* temp = head;

    //moves through the list and updates indices by starting at zero and
    //resetting all index data members
    while(temp != NULL)
    {
        temp->index = indexCounter;
        temp = temp->next;
        indexCounter++;
    }
}
