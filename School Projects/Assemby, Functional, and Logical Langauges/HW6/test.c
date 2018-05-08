#include <stdio.h>

//can't do it recursively
#define x while(y > 1){ result *= y; y--; }

void p()
{
    int y;
    printf("%d", y);
    y = 2;
}
    
void q()
{
    int y;
    y = 9;
}


void main()
{
    //p();
    //q();
    //p();


    int y = 5, result = 1;

    x
    
    //printf("%d", y);

    //while(y > 1)
    //{
    //    result *= y;
    //    y--;
    //}
    
    printf("%d\n", result);



}
