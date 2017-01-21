/**********************************************************************/
/*PROGRAM:      Project 12 (strings.cpp)                              */
/*                                                                    */
/*AUTHOR:       Bryan Kline                                           */
/*                                                                    */				
/*DATE:         12/04/15                                              */
/*                                                                    */
/*REVISIONS:    1                                                     */
/*                                                                    */	
/*PURPOSE:      Implementation of string functions.                   */
/*                                                                    */
/**********************************************************************/

#include <iostream>
#include "strings.h"

using namespace std;

//Function that copies one string into another.
void strcpy(char* dest, const char* source)
{	
    //Event controlled loop that copies what one
    //string pointer points to into the position
    //the other points to and increments the pointers
    //while the source string pointer is not the null
    //terminator.
    while(*source != '\0')
    {
        *dest = *source;
        dest++;		
        source++;
    }
    *dest = '\0';	
}

//Function that appends one string to the end of the other
//and returns it as a new string in the form of a pointer 
//to a char.
char* strcat(const char* dest, const char* source)
{
    int length;
    char* string;
    char* stringPtr;

    //The variable length is assigned the value of function calls to the strlen
    //with the destination and source string pointers as arguments plus one for
    //the null terminator.
    length = ((strlen(dest) + strlen(source)) + 1);

    //The string pointer string is dynamically allocated memory of size length.
    string = new char[length];
    stringPtr = string;

    //Event controlled loop that, while the destination pointer is not pointing
    //to the null character, assigns the char the destination pointer is pointing
    //to what the newly allocated string pointer is pointing to and the pointers
    //are incremented.
    while(*dest != '\0')
    {
        *stringPtr = *dest;
        stringPtr++;		
        dest++;
    }

    //Event controlled loop that, while the source pointer is not null, similarly
    //copies in the chars that the source pointer points to where the string
    //pointer points and the pointers are incremented.
    while(*source != '\0')
    {
        *stringPtr = *source;
        stringPtr++;		
        source++;
    }

    //The new string pointer has a null terminator added to where it points.
    *stringPtr = '\0';

    //The string pointer that is still pointing at the home position is returned.
    return string;
}

//Function that compares two strings and returns a bool
//corresponding to whether or not they match. 
bool strcmp(const char* string1, const char* string2)
{
    bool match;

    match = true;

    //Event controlled loop that, while what neither pointer
    //points to is the null terminator, checks if they are
    //equal to each other and the pointers are incremented.
    while((*string1 != '\0')&&(*string2 != '\0'))
    {	
        //If at any point what the pointers point to are not
        //equal then the bool match is set to false.
        if((*string1) != (*string2))
        {
            match = false;
        }
        string1++;
        string2++;
    }

    //If after the above loop either is not pointing at the
    //null terminator then they are different and match
    //is set to false.
    if((*string1 != '\0')||(*string2 != '\0'))
    {
        match = false;
    }

    //The bool match is returned.
    return match;
}

//Function that returns the length of a string.
int strlen(const char* string)
{
    int length;

    length = 0;

    //Event controlled loop that increments int length
    //and the pointer while the pointer is not pointing
    //at the null terminator.
    while(*string != '\0')
    {
        length++;
        string++;	
    }

    //The value length is returned.
    return length;
}


//Function that clears a string by assigning the first element in
//the string the null terminator.
void strclear(char* string)
{
    //Assigns the first element in the string the null terminator.
    *string = '\0';
}

//Function that returns a new string as a char pointer which 
//is the substring of the original between starting and ending
//positions.
char* substr(const char* string1, int start, int end)
{
    int i;
    int j;
    int length;
    char* string2;
    char* stringPtr;	

    length = strlen(string1);

    //If statement that checks to see that start is less than end, they
    //are both greater or equal to zero, and that end is greater than
    //length.
    if((start <= end)&&((start >= 0)&&(end >= 0))&&(end < length))
    {
        //A string pointer, string2, is allocated memory of the size of the
        //difference between the end and start positions passed into the
        //function plus two which makes it large enough for the substring
        //and the null terminator.
        string2 = new char[((end - start) + 2)];
        stringPtr = string2;

        //A counter controlled loop increments the string pointer to the first
        //position.
        for(i = 0; i < start; i++)
        {
            string1++;
        }

        //Counter controlled loop that copies in what the string pointer points
        //to over to the newly created memory as many times as the difference
        //between end and start, and the pointers are incremented
        for(j = 0; j < ((end - start) + 1); j++)
        {
            *stringPtr = *string1;
            stringPtr++;
            string1++;
        }	

        //The new string pointer is set back to home after what it
        //points to is assigned the null terminator.
        *stringPtr = '\0';
        stringPtr = string2;

        //The new string pointer is returned. 
        return stringPtr;
    }
    //If any of the above are false then the pointer is set to NULL
    //and returned.
    else
    {
        stringPtr = NULL;
        return stringPtr;
    }
}

//Function that inserts one string into another at a position
//taken in as an argument.
char* strinsert(const char* string1, const char* string2, int index)
{
    int i;
    int length1;
    int length2;
    char* newString;
    char* newStringPtr;
    const char* stringPtr1;
    const char* stringPtr2;

    stringPtr1 = string1;
    stringPtr2 = string2;

    //The int length is assigned the value of the result of the 
    //function calls to strlen with the string pointers passed in
    //added together.
    length1 = (strlen(stringPtr1) + strlen(stringPtr2));

    length2 = strlen(string1);

    //If statement that checks to if index is less than the length of
    //the first string.
    if(index < length2)
    {
        //A new string pointer has memory allocated to it of size length
        //plus one, for the null terminator, and another pointer is set 
        //equal to it as the home position.
        newString = new char[(length1 + 1)];
        newStringPtr = newString;

        //Counter controlled loop that copies in the first string
        //into the new string upt to the position letter by
        //dereferencing the pointers and assigning one to the other 
        //and the pointers are incremented.
        for(i = 0; i < index; i++)
        {
            *newStringPtr = *stringPtr1;	
            newStringPtr++;
            stringPtr1++;
        }

        //Event controlled loop that copies in what the second
        //string points to into what the new string pointer
        //points to while the second string pointer is not 
        //pointing to the null terminator and the pointers
        //are incremented.
        while(*stringPtr2 != '\0')
        {
            *newStringPtr = *stringPtr2;	
            newStringPtr++;
            stringPtr2++;
        }

        //Event controlled loop that copies in what the first
        //string points to into what the new string pointer
        //points to while the first string pointer is not
        //pointing to the null terminator and the pointers
        //are incremented.
        while(*stringPtr1 != '\0')
        {
            *newStringPtr = *stringPtr1;
            newStringPtr++;
            stringPtr1++;	
        }

        //The null terminator is assigned to what the new string
        //pointer points to.
        *newStringPtr = '\0';

        //The home position of the new string is returned.
        return newString;
    }
    //If index is not less than length2 then the string is set
    //to NULL and returned.
    else
    {
        newString = NULL;
        return newString;
    }
}

//Function that writes one string over the chars in another
//at the position passed in as an argument.
void strreplace(char* string1, const char* string2, int index)
{
    int i;
    int length;
    char* stringPtr1;
    const char* stringPtr2;

    //The variable length is assigned the value returned by the
    //function call to strnlen on the first string pointer.
    length = strlen(string1);

    stringPtr1 = string1;
    stringPtr2 = string2;

    //If statement that checks whether or not the position, letter, passed
    //in is greater than the length, if so then nothing is done.
    if(index <= length)
    {
        //If letter is less than or equal to length then the 
        //pointer is incremented to letter.
        for(i = 0; i < index; i++)
        {
            stringPtr1++;
        }

        //While neither string pointer is pointing to the null
        //terminator the char that one points to is copied in
        //to where the other points and the pointers are incremented.
        while((*stringPtr1 != '\0')&&(*stringPtr2 != '\0'))
        {
            *stringPtr1 = *stringPtr2;
            stringPtr1++;
            stringPtr2++;
        }
    }
}

//Function that fills a string with some number of characters at
//some position indicated by arguments passed into the function.
void strfill(char* string, char character, int index, int number)
{
    int i;
    int length;

    //The variable length is assigned the value returned by the
    //function call to strnlen on the string pointer.
    length = strlen(string);

    //If statement that checks whether or not the position, letter, passed
    //in is greater than the length, if so then nothing is done.
    if(index <= length)
    {
        //If letter is less than or equal to length then the 
        //pointer is incremented to letter minus one.
        for(i = 0; i < index; i++)
        {		
            string++;
        }

        i = 0;	

        //While the string pointer is not pointing to the null
        //terminator and the counter i is less than the number
        //of characters to be copied in, then the dereferenced
        //string pointer is assigned the character and the pointer
        //and the counter i are incremented.
        while((*string != '\0')&&(i < number))
        {
            *string = character;
            string++;
            i++;
        }
    }
}

//Function that reverses the order of chars in a string.
void strreverse(char* string)
{
    int i;
    int j;
    int x = 0;
    int length;
    char tempChar;
    char* stringPtr1;
    char* stringPtr2;

    stringPtr1 = string;
    stringPtr2 = string;

    //The variable length is assigned the value returned by the
    //function call to strnlen on the string pointer.
    length = strlen(string);

    //Counter controlled loop that goes up to half way through
    //the string and copies in what the string points to
    //into a tempChar, enters another for loop to 
    //increment another pointer pointing to the string to
    //get to the end of the string, then what that pointer
    //points to is copied into what the first points to
    //and the char in tempChar is copied into what the pointer
    //that points to the end points to.
    for(i = 0; i < (length/2); i++)
    {
        tempChar = *stringPtr1;

        for(j = 0; j < ((length - x) - 1); j++)
        {
            stringPtr2++;
        }

        *stringPtr1 = *stringPtr2;
        *stringPtr2 = tempChar;
        stringPtr2 = string;
        stringPtr1++;		
        x++;
    }
}
