
// Bryan Kline
// Dec. 2016
// Main driver to test TreeNode and TextTree classes (main.cpp)

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "TextTree.h"

using namespace std;

int main()
{
    TextTree myTree;
    TreeNode *temp;

    int choice = 0;
    char labelBuffer[1000];
    char contentBuffer[10000];
    bool firstAddition = true;

    //menu system which prompts the user with choices about what to do with 
    //the TextTree for testing purposes
    while(choice != 7)
    {
        cout << "Enter 1 to add to the tree." << endl;
        cout << "Enter 2 to remove from the tree." << endl;
        cout << "Enter 3 to check if the tree is empty." << endl;
        cout << "Enter 4 to clear the tree." << endl;
        cout << "Enter 5 to print the tree." << endl;
        cout << "Enter 6 to search for a label." << endl;
        cout << "Enter 7 to quit." << endl;
        cin >> choice;

        switch(choice)
        {
            //adds a node to the TextTree after the user inputs label and content
            //strings
            case 1:

                cout << "Adding a node to the tree." << endl;       
 
                cout << "Enter a label:" << endl;
                cin >> labelBuffer;

                cout << "Enter text:" << endl;
                cin >> contentBuffer;
                
                myTree.addNode(temp, labelBuffer, contentBuffer);

                if(firstAddition)
                {
                    temp = myTree.getRoot();
                    firstAddition = false;    
                }
            

            break;

            //removes the subtree at a specified node
            case 2:
            
                cout << "Removing from the tree." << endl;
            
                if(temp != NULL)
                {
                    myTree.clear(temp); 
                }

            break;

            //checks whether or not the TextTree is empty
            case 3:

                cout << "Checking if the tree is empty." << endl;

                if(myTree.isEmpty())
                {
                    cout << "The tree is empty." << endl;
                }   
                else
                {
                    cout << "The tree is not empty." << endl;
                } 

            break;

            //clears the entire TextTree
            case 4:

                cout << "Clearing the tree." << endl;
                temp = myTree.getRoot();
                myTree.clear(temp);

            break;

            //prints the contents of the TextTree to the screen
            case 5:

                cout << "Printing the tree." << endl;
                myTree.diagnosticPrint();

            break;

            //searches the TextTree for a node with a particular label, is the
            //primary method for navigating through the TextTree in order to
            //add a node or remove a subtree
            case 6:

                cout << "Searching for a lable." << endl;

                cout << "Enter a label: " << endl;
                cin >> labelBuffer;

                temp = myTree.searchTree(labelBuffer);
                cout << "At node: " << myTree.getLabel(temp) << endl;

                if(temp == NULL)
                {
                    cout << "That node doesn't exist, try again." << endl;
                }

            break;

            //exits the program
            case 7:

                cout << "Exiting program." << endl;

            break;

            //default for invalid input
            default:

                cout << "Enter a valid selection." << endl;

            break;
        }

        //clears invalid input
		cin.clear();
		cin.ignore();
    }

    return 0;
}

