
// Bryan Kline
// Dec. 2016
// TreeNode and TextTree class headers (TextTree.h)

#ifndef TEXTTREE_H
#define TEXTTREE_H

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////
//TreeNode
/////////////////////////////////////////////////////////////////////////////////////////

//TreeNode class header 
class TreeNode
{
    public:
        
        //TreeNode parameterized constructor
        TreeNode(TreeNode* parentNode, char* labelName, char* contentString, bool leaf);

        //TreeNode destructor
        ~TreeNode();     

        //TreeNode method to add a child to the node
        void addChild(char* labelName, char* contentString); 
          
    friend class TextTree;

    private:

        //TreeNode method to remove null children from a node's children array
        //after a child has been deleted
        void shiftChildren();

        TreeNode* parent;
        TreeNode** children;
        int childrenCount;
        char* label;
        char* content;
        bool isLeaf;
};

/////////////////////////////////////////////////////////////////////////////////////////
//TextTree
/////////////////////////////////////////////////////////////////////////////////////////

//TextTree class header
class TextTree
{
    public:
        
        //TextTree parameterized constructor
        TextTree();

        //TextTree destructor
        ~TextTree();        
        
        //TextTree method to get a the child node at a given index in a node's 
        //children array
        TreeNode* getChildNode(TreeNode* currentNode, int childNumber);

        //TextTree method to get the current node in the TextTree
        TreeNode* getCurrentNode(); 

        //TextTree method to get the root node of the TextTree
        TreeNode* getRoot();

        //TextTree method to search for a node with a particular label in the TextTree
        TreeNode* searchTree(char* labelName);

        //TextTree method to add a node in the TextTree as a child to a particular node
        void addNode(TreeNode* currentNode, char* labelName, char* contentString);

        //TextTree method to clear an entire subtree of a particular node
        void clear(TreeNode* &currentNode);

        //TextTree method to print the contents of the tree to the screen
		void diagnosticPrint();

        //TextTree method to set the label of a particular node
        void setLabel(TreeNode* currentNode, char* string);

        //TextTree method to set the content of a particular node
        void setContent(TreeNode* currentNode, char* string);

        //TextTree method to get the label of a particular node as a separate string
        char* getLabel(TreeNode* currentNode) const;

        //TextTree method to get the content of a particular node as a separate string
        char* getContent(TreeNode* currentNode) const;

        //TextTree method to check if the tree is empty
        bool isEmpty() const;

    friend class TreeNode;

    private:

        //TextTree method to recursively help diagnosticPrint 
        void printHelper(TreeNode* currentNode);

        //TextTree method to recursively help clear 
        void clearHelper(TreeNode* &currentNode);

        //TextTree method to recursively help search 
        TreeNode* searchHelper(TreeNode* &currentNode, char* labelName);

        TreeNode* root;
        TreeNode* current;
        int totalNodes;

};

#endif
