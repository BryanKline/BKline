#include <iostream>

using namespace std;

class Stack 
{
    public:

        Stack(int = 10);
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

        int max;
        int top;

        //only used in stack (stay) implementation
        int actual;
        char* data;
};

