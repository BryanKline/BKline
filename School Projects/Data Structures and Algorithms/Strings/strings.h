/**********************************************************************/
/*PROGRAM:      Project 12 (strings.h)                                */
/*                                                                    */
/*AUTHOR:       Bryan Kline                                           */
/*                                                                    */				
/*DATE:         12/04/15                                              */
/*                                                                    */
/*REVISIONS:    1                                                     */
/*                                                                    */	
/*PURPOSE:      String function specification.                        */
/*                                                                    */
/**********************************************************************/

#include <iostream>

using namespace std;

//Function headers for string functions.
void strcpy(char* dest, const char* source);
char* strcat(const char* dest, const char* source);
bool strcmp(const char* string1, const char* string2);
int strlen(const char* string);
void strclear(char* string);
char* substr(const char* string1, int start, int end);
char* strinsert(const char* string1, const char* string2, int index);
void strreplace(char* string1, const char* string2, int index);
void strfill(char* string, char character, int index, int number);
void strreverse(char* string);
