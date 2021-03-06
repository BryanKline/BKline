#include <iostream>

using namespace std;

class Stack;

class Node
{
    private:

        Node(char, Node*);

        friend ostream& operator << (ostream&, const Stack&);

        friend class Stack;

        char data;
        Node* next;
};


class Stack
{
    public:
        Stack(int = 0);
        Stack(const Stack&);
        ~Stack();

        bool push(char);
        bool pop(char&);
        bool empty() const;
        bool full() const;
        bool clear();

        Stack& operator = (const Stack&);
        bool operator == (const Stack&) const;

        friend ostream& operator << (ostream&, const Stack&);

    private:

        Node* top;
};
