
// Bryan Kline
// Feb. 2016
// StringNode and StringList class headers (StringNode.h)

//StringNode class header
class StringNode
{
    public:

        //StringNode parameterized constructor
        StringNode(char* string, int number, int section, StringNode *nextNode);

        //StringNode destructor
        ~StringNode();

        friend class StringList;
    
    private:
    
        char* nodeString;
        int index;
        int currentSection;    
        StringNode *next;
};

//StringList class header
class StringList
{
    public:

        //StringListdefault constructor
        StringList();

        //StringList destructor
        ~StringList();

        //StringList method to check if the list is empty
        bool isEmpty();

        //StringList method to add a StringNode to the list
        bool addString(char* string, int number, int section, StringNode *nextNode, bool newSection);

        //StringList method to remove a StringNode from the list
        bool removeString(int index);

        //StringList method to change the value of the string at a given index in the list
        bool setString(int index, char* string);

        //StringList method to check if at the end of the list
        bool atEnd(int index);

        //StringList method to get the size of the list
        int getSize();

        //StringList method to get a string from a node at a given index
        char* getString(int index);

        //StringList method to print the list
        void diagnosticPrint();
        

        friend class StringNode;

    private:

        //StringList method to move through the list and update the indices
        void setIndices();

        int size;
        int sections;
        int currentIndex;
        StringNode *head;
        StringNode *current;
        StringNode *tail;
};
