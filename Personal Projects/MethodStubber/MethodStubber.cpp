
// Bryan Kline
// Feb. 2016
// Main driver for MethodStubber program which uses StringList class (MethodStubber.cpp)
// MethodStubber takes in a C++ header file as the first command line argument and, if 
// it adheres to a specific format, generates an implementation file with all methods
// stubbed out as a time saving mechanism

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "StringNode.h"

using namespace std;

//free function which takes in a string and char and checks that the string contains that char
bool hasCharacter(char* string, char character);

//free function which takes in a ofstream object, sends open and close curly braces to the stream
void functionStub(ofstream &outFile, bool returnType);

//free function which takes in a file name and a StringList obeject and reads in the file into the list
void readHeader(char* fileName, StringList &list);

//free function to remove strings in the list which are not to be included in the implementation
void headerRemoval(StringList &list);

//free function which takes in a string and removes the semicolon delimiter
void removeDelimiter(char* string);

//free function which takes in a string, a file name, and changes the file name extension 
char* makeCPP(char* string, bool upper);

//free function that takes in a list and counts the number of relevant lines in it
int lineCounter(StringList &list, int &offset);

//free function that takes in a string, a file name, and StringList, and writes the list to the file
void fileWriter(char* fileName, StringList &list);


//main
int main(int argc, char* argv[])
{    
    StringList list;
 
    //makeCPP is called on the command line argument corresponding to the header file
    //to created the file name for the implementation file, lowercase
    char* fileName = makeCPP(argv[1], false);
    
    //readHeader is called on the command line argument corresponding to the header file
    //to open the file and read it into the StringList
    readHeader(argv[1], list);

    //headerRemoval is called on the StringList to removed extraneous strings
    headerRemoval(list);

    //fileWriter is called on the implementation file name and the StringList to write
    //to the output file
    fileWriter(fileName, list);

    return 0; 
}

//free function which takes in a string and char and checks that the string contains that char
//returns bool corresponding to whether the string contains that char
bool hasCharacter(char* string, char character)
{
    int index = 0;

    //moves through the string and returns true if it finds the given
    //char
    while(string[index] != '\0')
    {
        if(string[index] == character)  
        {
            return true;
        } 

        index++; 
    } 

    return false; 

}

//free function which takes in a ofstream object, sends open and close curly braces
//to the stream as well as "return ;" if it has a return type
//void 
void functionStub(ofstream &outFile, bool returnType)
{
    outFile << "{" << endl << endl;

    //if the method has a return type then "return ;" is sent to the stream
    if(returnType)
    {
        outFile << "\treturn ;" << endl;
    }

    outFile << "}" << endl << endl;
}

//free function which takes in file name and a StringList obeject and reads in the file's
//contents to the string
//void
void readHeader(char* fileName, StringList &list)
{    
    int counter = 0;
    char buffer[100];
    bool startFlag = false;
    ifstream inFile;

    //the file is opened
    inFile.open(fileName);

    //while not at the end-of-file string, "#endif", moves through the file and adds 
    //its contents to the list; assumes "#ifndef" and "#endif" preprocessor directives
    while(strcmp(buffer, "#endif") != 0)
    {
        inFile >> buffer;

        if(strcmp(buffer, "#ifndef") == 0)
        {  
            startFlag = true;
        }  

        if(startFlag)
        {
            list.addString(buffer, counter, counter, NULL, false);
            counter++;
        }
    }
    
    //the file is closed
    inFile.close();
}

//free function to remove strings in the list which are not to be included in the implementation
//void
void headerRemoval(StringList &list)
{
    int indexCounter = 0, tempCounter;

    char buffer[100];

    bool newLineFlag = false;
    bool endLineFlag = false;
    bool classFlag = false;

    //moves through the list which contains all strings from the header
    while(!list.atEnd(indexCounter))
    {
        strcpy(buffer, list.getString(indexCounter));     

        //once at the end of a line a flag is set
        if(hasCharacter(buffer, ';') && classFlag && strcmp(buffer, "};") != 0)
        {
            endLineFlag = true;
        }

        //once the class name statement is reached a flag is set
        if(strcmp(buffer, "class") == 0)        
        {
            classFlag = true;
        }

        //if the current string in the list is "friend" then the entire line it occurs on is removed
        if(strcmp(buffer, "friend") == 0)
        {  
            while(!hasCharacter(buffer, ';'))
            {
                list.removeString(indexCounter);
                strcpy(buffer, list.getString(indexCounter));                       
            }

            list.removeString(indexCounter);
            newLineFlag = true;
            continue;
        }
    
        //if the current string in the list is the public or private statements or the open or close curly braces
        //the that string is removed; 
        if((strcmp(buffer, "public:") == 0) || (strcmp(buffer, "private:") == 0) || (strcmp(buffer, "{") == 0) || (strcmp(buffer, "};") == 0))
        {  
            list.removeString(indexCounter);
            newLineFlag = true;
            continue;
        }
        
        //if at a new line then the line is moved through, removing the line if it's
        //not a method prototype, i.e. a data member or other statement
        if(newLineFlag)
        {
            tempCounter = indexCounter;

            while(!hasCharacter(buffer, ';'))
            {
                if(hasCharacter(buffer, '('))
                {
                    newLineFlag = false;
                    break;
                }
                tempCounter++;
                strcpy(buffer, list.getString(tempCounter));
            }

            if(hasCharacter(buffer, ';') && hasCharacter(buffer, '('))
            {
                newLineFlag = false;
            }
            
            //if the end of the line has been reached and it's not a method then the line is removed
            if(newLineFlag)
            {
                strcpy(buffer, list.getString(indexCounter));

                while(!hasCharacter(buffer, ';'))
                {
                    list.removeString(indexCounter);
                    strcpy(buffer, list.getString(indexCounter));                        
                }

                list.removeString(indexCounter);
                indexCounter--;                  
            }
        }

        if(endLineFlag)
        {
            newLineFlag = true;
            endLineFlag = false;
        }   

        indexCounter++;
    }
}

//free function which takes in a string and removes the semicolon delimiter
//if it is terminated by one
//void
void removeDelimiter(char* string)
{
    int index = 0;

    //moves through the string and removes the semicolon at the end
    while(string[index] != '\0')
    {
        if(string[index] == ';')
        {
            string[index] = '\0';
        }   
        index++; 
    }
}

//free function which takes in a string, a file name, and a bool corresponding to whether
//to make it uppercase or lowercase, and changes the file name extension from ".h" to ".cpp"
//returns string with new file name extension
char* makeCPP(char* string, bool upper)
{
    int index = 0;
    int length = strlen(string) + 3;

    char* newString = new char[length];

    //moves through the string, copying the contents of the input string into a new
    //string, discards ".h", or "_H", with ".cpp" or "_CPP"
    while(string[index] != '\0')
    {
        newString[index] = string[index];

        if(string[index] == '_' || string[index] == '.')
        {
            if(upper)
            {
                newString[index + 1] = 'C';
                newString[index + 2] = 'P';
                newString[index + 3] = 'P';    
                newString[index + 4] = '\0';
                return newString;        
            }
            else
            {
                newString[index] = '.';
                newString[index + 1] = 'c';
                newString[index + 2] = 'p';
                newString[index + 3] = 'p';    
                newString[index + 4] = '\0';
                return newString;
            }
        }   
        index++; 
    }
        
    return newString;  
}

//free function that takes in a list and counts the number of relevant lines in it
//returns int corresponding to the number of lines in the list, which holds the header strings
//parameter offset returns how many spaces to ADD HERE ................
int lineCounter(StringList &list, int &offset)
{
    int size = 0, counter = 0;
    char buffer[100];
    bool templateFlag = false;
    bool classFlag = false;

    strcpy(buffer, list.getString(counter)); 

    //moves through the list and counts up the total lines, either those delimited with 
    //semicolons, with close angle brackets, or with preprocessor directives and returns
    //that count 
    while((strcmp(buffer, "#endif") != 0))    
    {
        strcpy(buffer, list.getString(counter));     

        //if the class is templated then offset is set to 5 plus the line the template occurs at, 
        //if not it's set to 2 plus the line the class name occurs at 
        if((strcmp(buffer, "template") == 0))    
        {
            offset = counter + 5;
            templateFlag = true;
        }
        if((strcmp(buffer, "class") == 0) && !templateFlag)    
        {
            classFlag = true;
            offset = counter + 2;
        }
        
        if(hasCharacter(buffer, '>') && !templateFlag && !classFlag)
        {
            size++;
        } 
        if(hasCharacter(buffer, ';'))
        {
            size++;
        } 

        if((strcmp(buffer, "#ifndef") == 0) || (strcmp(buffer, "#define") == 0) || (strcmp(buffer, "#endif") == 0))
        {
            size++;
        }

        counter++;       
    }

    return size;
}

//free function that takes in a string, a file name, and StringList, and writes the list to the file
//with all methods stubbed out
//void
void fileWriter(char* fileName, StringList &list)
{
    int functionStart, size, counter = 0, index = 0;
    
    char buffer[100];
    char className[100];
    char templateString1[100];
    char templateString2[100];

    bool classFlag = false;
    bool templateFlag = false;
    bool typeFlag = false;
    bool returnFlag = false;

    ofstream outFile;   

    //opens the file
    outFile.open(fileName);

    size = lineCounter(list, functionStart);

    //moves through the list, getting the strings from the list and writing them to the file,
    //making checks along the way so that additional strings can be written to the file to
    //propperly stub it out
    for(counter = 0; counter < size; counter++)
    {
        strcpy(buffer, list.getString(index)); 

        //if at the begging of the header, i.e. before the method prototypes, checks for 
        //preprocessor directives, template statements, class name, and using statements
        //are made
        if(index < functionStart)
        {
            //if it's at a preprocessor directive then makeCPP is called if the string contains
            //an underscore, and in either case it's written the file
            if(hasCharacter(buffer, '#'))
            {
                outFile << buffer << " ";
                index++;
                strcpy(buffer, list.getString(index)); 

                if(hasCharacter(buffer, '_'))
                {
                    list.setString(index, makeCPP(list.getString(index), true));
                    strcpy(buffer, list.getString(index));
                }

                outFile << buffer << endl;
                index++;
                continue;
            }

            //if it's at a template statement then a flag is set and a template
            //string is created which will be written to the file before each method
            if((strcmp(buffer, "template") == 0))    
            {    
                templateFlag = true;
                index++;
                strcpy(templateString1, list.getString(index));
                index++;
                strcpy(templateString2, list.getString(index));
                index++;
                continue;
            }

            //if it's at the class name then a class name string is created so that it
            //can be used in each method with along with the scope resolution operator 
            if((strcmp(buffer, "class") == 0))    
            {
                strcpy(className, list.getString(index + 1));
                index += 2;
                continue; 
            }

            //if it's at a using statement then the entire thing is written to the file
            if((strcmp(buffer, "using") == 0))
            {
                
                outFile << endl << buffer << " "; 
                index++;
                strcpy(buffer, list.getString(index)); 
                outFile << buffer << " ";
                index++;
                strcpy(buffer, list.getString(index)); 
                outFile << buffer << endl << endl;
                index++;
                continue;
            }
        }
        //once it gets to the methods then each is written to the file along with the class name
        //and scope resolution operator, open and close curly braces, return statement if it needs 
        //one, preceded by the template string if it's templated
        else
        {
            //if the class is templated then the template string is written to the file
            if(templateFlag && counter < size - 1)
            {
                outFile << "template " << templateString1 << " " << templateString2 << endl;
            }
        
            //if the current string doesn't have a semicolon then it's checked for open parenthesis,
            //meaning it's the method name so that if templated the template syntax can be inserted
            //along with the class name and scope resolution operator
            while(!hasCharacter(buffer, ';'))
            {
                if(typeFlag && hasCharacter(buffer, '('))
                {
    
                    outFile << className;

                    if(templateFlag)
                    {
                        outFile << "<" << templateString2;
                    }

                    outFile << ":: ";

                    typeFlag = false;
                    
                    if(strcmp(buffer, "void") != 0)
                    {
                        returnFlag = true;
                    } 
                }           

                outFile << buffer << " ";

                if(typeFlag && !(strcmp(buffer, "const") == 0) && !hasCharacter(buffer, '('))
                {
                    outFile << className;

                    if(templateFlag)
                    {
                        outFile << "<" << templateString2;
                    }

                    outFile << ":: ";

                    typeFlag = false;
                    
                    if(strcmp(buffer, "void") != 0)
                    {
                        returnFlag = true;
                    }    
        
                }

                index++;
                strcpy(buffer, list.getString(index));      
            }
            //if the string at that point in the list as the semicolon delimiter, removeDelimiter is
            //called to remove it
            if(hasCharacter(buffer, ';'))
            {
                if(hasCharacter(buffer, '('))
                {
                    outFile << className;

                    if(templateFlag)
                    {
                        outFile << "<" << templateString2;
                    }

                    outFile << ":: ";
                }

                removeDelimiter(list.getString(index));
                strcpy(buffer, list.getString(index));
            }
            index++;
            typeFlag = true;
            outFile << buffer << endl;
            functionStub(outFile, returnFlag);
            returnFlag = false; 
        }

        //once at the end it writes preprocessor directive to the file
        if(counter == size - 1)
        {
            outFile << "#endif" << endl;
        }
    }
 
    //closes the file
    outFile.close();
}
