
// Bryan Kline
// Dec. 2016
// TreeNode and TextTree class implementations (TextTree.cpp)

#ifndef TEXTTREE_CPP
#define TEXTTREE_CPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "TextTree.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////
//TreeNode
/////////////////////////////////////////////////////////////////////////////////////////

//TreeNode parameterized constructor
TreeNode:: TreeNode(TreeNode* parentNode, char* labelName, char* contentString, bool leaf)
{
    int length;

    parent = parentNode;
    children = NULL;
    childrenCount = 0;
    isLeaf = leaf;

    length = strlen(labelName) + 1;
    label = new char[length];
    strcpy(label, labelName);

    length = strlen(contentString) + 1;
    content = new char[length];
    strcpy(content, contentString);
}

//TreeNode destructor
TreeNode:: ~TreeNode()
{
    delete[] label;
    delete[] content;
    delete[] children;

    children = NULL;
    parent = NULL;
}

//TreeNode method to add a child to the node
//void
void TreeNode:: addChild(char* labelName, char* contentString)
{
    int counter;
    TreeNode** temp; 

    //if there are no children at the node one is created
    if(childrenCount == 0)
    {
        children = new TreeNode*;
        *children = new TreeNode(this, labelName, contentString, true);
        childrenCount++;
        isLeaf = false;
    }
    //if there are already children then space is made for larger child array, new 
    //pointers pointed at old children, a new children array is created, and the
    //array is deleted
    else
    {
        temp = new TreeNode*[childrenCount + 1];

        for(counter = 0; counter < childrenCount; counter++)
        {
            temp[counter] = children[counter];
        }

        temp[counter] = new TreeNode(this, labelName, contentString, true);  
        delete[] children;
        children = temp;
        childrenCount++;  
    }
}

//TreeNode method to remove null children from a node's children array 
//after a child has been deleted
//void
void TreeNode:: shiftChildren()
{
    int counter, tempCounter = 0;
    TreeNode** temp;     

    //if there is only one child in the array then the entire array is deleted
    if(childrenCount == 1)
    {
        delete children;
        children = NULL;
        childrenCount = 0;
    }
    //if there are more than one child then a new array is created with the smaller
    //size, the children are moved to the new array, and the old array is deleted
    else
    {
        temp = new TreeNode*[childrenCount - 1]; 

        for(counter = 0; counter < childrenCount; counter++)
        {
            if(children[counter] != NULL)
            {
                temp[tempCounter] = children[counter];    
                tempCounter++;            
            }       
        }    

        delete[] children;
        children = temp;
        childrenCount--;     
    }    
}

/////////////////////////////////////////////////////////////////////////////////////////
//TextTree
/////////////////////////////////////////////////////////////////////////////////////////

//TextTree parameterized constructor
TextTree:: TextTree()
{
    root = NULL;
    current = NULL;
    totalNodes = 0;
}

//TextTree destructor
TextTree:: ~TextTree()
{
    clear(root);
}

//TextTree method to get a the child node at a given index in a node's 
//children array
//returns TreeNode* corresponding to the child node at the given index
TreeNode* TextTree:: getChildNode(TreeNode* currentNode, int childNumber)
{
    //if the children array is not empty and the child index is valid, that node
    //is returned, otherwise the current node is returned
    if(currentNode->children != NULL && childNumber < currentNode->childrenCount)
    {
        return currentNode->children[childNumber]; 
    }

    return currentNode;
}

//TextTree method to get the current node in the TextTree
//returns TreeNode* at the current node
TreeNode* TextTree:: getCurrentNode()
{
    return current;
}

//TextTree method to get the root node of the TextTree
//returns TreeNode* at the root
TreeNode* TextTree:: getRoot()
{
    return root;
}

//TextTree method to search for a node with a particular label in the TextTree
//returns TreeNode* corresponding to the retrieved node
TreeNode* TextTree:: searchTree(char* labelName)
{
    //returns the result from a call to searchHelper on the root
    return searchHelper(root, labelName);
}

//TextTree method to add a node in the TextTree as a child to a particular node
//void
void TextTree:: addNode(TreeNode* currentNode, char* labelName, char* contentString)
{
    int index = 0;

    //if the root is null then a node is created at the root
    if(root == NULL)
    {
        root = new TreeNode(NULL, labelName, contentString, true);
        current = root;
    }
    //if the root is not null then a call to the current node's addChild method
    //at the node
    else
    {
        currentNode->addChild(labelName, contentString);    
    }

    totalNodes++;
}

//TextTree method to clear an entire subtree of a particular node
//void
void TextTree:: clear(TreeNode* &currentNode)
{
    //if the current node is not NULL then a call to clearHelper removes it
    //and its subtree
    if(currentNode != NULL)
    {   
        clearHelper(currentNode);        
    }
}

//TextTree method to print the contents of the tree to the screen
//void
void TextTree:: diagnosticPrint()
{
    //if the tree is not empty then its contents are printed to the screen
    if(!isEmpty())
    {   
        printHelper(root);        
    }
    else
    {
        cout << "The tree is empty." << endl;
    }
}

//TextTree method to set the label of a particular node
//void
void TextTree:: setLabel(TreeNode* currentNode, char* string)
{
    int length = strlen(string) + 1;

    if(currentNode->label != NULL)
    {
        delete[] currentNode->label;
    }    
    currentNode->label = new char[length];
    strcpy(currentNode->label, string);
}

//TextTree method to set the content of a particular node
//void
void TextTree:: setContent(TreeNode* currentNode, char* string)
{
    int length = strlen(string) + 1;

    if(currentNode->content != NULL)
    {
        delete[] currentNode->content;
    }    
    currentNode->content = new char[length];
    strcpy(currentNode->content, string);
}

//TextTree method to get the label of a particular node as a separate string
//returns char* corresponding to the label at the current node
char* TextTree:: getLabel(TreeNode* currentNode) const
{
    int length;
    char* string;

    if(currentNode->label != NULL)
    {    
        length = strlen(currentNode->label) + 1;
        string = new char[length];
        strcpy(string, currentNode->label);

	    return string;
    }
        
    return NULL;
}

//TextTree method to get the content of a particular node as a separate string
//returns char* corresponding to the content at the current node
char* TextTree:: getContent(TreeNode* currentNode) const
{
    int length;
    char* string;

    if(currentNode->content != NULL)
    {    
        length = strlen(currentNode->content) + 1;
        string = new char[length];
        strcpy(string, currentNode->content);

	    return string;
    }

	return NULL;
}

//TextTree method to check if the tree is empty
//returns bool corresponding to whether or not the TextTree is empty
bool TextTree:: isEmpty() const
{
    if(root == NULL && totalNodes == 0)
    {
        return true;
    }        

    return false;
}

//TextTree method to recursively help diagnosticPrint 
//void
void TextTree:: printHelper(TreeNode* currentNode)
{
    int index;  

    //if at a leaf node the data members are printed to the screen
    //the isLeaf data member is not checked as it may be removed at a later point
    if(currentNode->children == NULL && currentNode->childrenCount == 0)
    {
        cout << currentNode->label << endl;
        cout << currentNode->content << endl;
        cout << endl;
    }    
    //if the node is not a leaf then the data members are printed and then 
    //function is called recursively on all its children nodes
    else
    {
        cout << currentNode->label << endl;
        cout << currentNode->content << endl;
        cout << endl;

        for(index = 0; index < currentNode->childrenCount; index++)
        {   
            printHelper(currentNode->children[index]);
        }
    }    
}

//TextTree method to recursively help clear
//void
void TextTree:: clearHelper(TreeNode* &currentNode)
{
    int counter = 0;  
    bool rootFlag = false;
    TreeNode *parentTemp, *temp;

    //if the current node is the root set flag, otherwise get the node's parent
    if(currentNode == root)
    {
        rootFlag = true;
    }
    else
    {
        parentTemp = currentNode->parent;
    }

    //if the children array is not empty, the function is called recursively on
    //the children
    if(currentNode->children != NULL && currentNode->childrenCount != 0)
    {
        while(currentNode->children != NULL)
        {   
            clearHelper(currentNode->children[0]);
        }
    } 

    //if the current node is not the root, navigate to its place in its
    //parent's children array, delete it, and set it to NULL 
    if(currentNode != root)
    {
        while(parentTemp->children[counter] != currentNode)
        {
            counter++;
        }

        temp = parentTemp->children[counter];
        delete temp;
        parentTemp->children[counter] = NULL;
        totalNodes--;
    }

    //if at the root, delete it, otherwise call shiftChildren on the current
    //node to remove NULL children from its array
    if(rootFlag)
    {
        delete root;
        root = NULL;
    }
    else
    {
        parentTemp->shiftChildren();    
    }
}

//TextTree method to recursively help search 
//returns TreeNode* corresponding to the retrieved node
TreeNode* TextTree:: searchHelper(TreeNode* &currentNode, char* labelName)
{
    int index;  

    //if the label is found then the node is returned
    if(currentNode != NULL && strcmp(currentNode->label, labelName) == 0)
    {
       return currentNode; 
    }
    //if the label is not found at the current node then the function is called
    //recursively on the node's children nodes
    else
    {
        if(currentNode->children != NULL && currentNode->childrenCount != 0)
        {
            for(index = 0; index < currentNode->childrenCount; index++)
            {
                if(searchHelper(currentNode->children[index], labelName) != NULL)
                {   
                    return searchHelper(currentNode->children[index], labelName);
                }
            }
            
            return NULL;
        } 
        else
        {
            return NULL;
        }   
    }
}


#endif
