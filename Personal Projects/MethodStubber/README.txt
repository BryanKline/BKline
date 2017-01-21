
MethodStubber

Brief:

A tool created for the purpose of reading in a C++ header file and creating 
an implementation file with blank, stubbed out class methods.

Detailed:

This is a tool I created for myself as a personal project which was intended
to increase my efficiency in writing implementation files in C++ from headers,
usually those provided by professors for class assignments.  This was written
while I was taking CS302, Data Structures and Algorithms, and will produce
a "stubbed out" or blank implementation file from a class header.  This saves
quite a bit of time in that transferring over the method headers and all 
attendant syntax is time consuming.

The program uses a simple linked list which holds strings to read in all the
data from the header file and then a number of free functions to parse out 
all the necessary data from the unnecessary data, remove the latter, and then write
the former to a new file, the implementation or ".cpp", along with all additional
syntax like the class name and scope resolution operator, open and curly braces and 
return statements, as well as template statements if the class is templated.

The header file must be in a particular format, it must have certain preprocessor
directives, #ifndef and #endif, and can deal with templated classes, which can
only have one templated type, and must be free of comments, though it can deal
with constants and data members.  The output is a ".cpp" file with preprocessor
and include directives as well as using statements followed by each method header,
with the class name and scope resolution operator in the correct position,
followed by open and close curly braces and a return statement if it has a return
type, all of which preceded by template statements if the class is templated.

There are small errors in the output under some circumstances, however as I 
wrote it for my own use, under circumstances that don't produce the errors, 
and as I want to preserve the code in its original state as an artifact 
documenting the evolution of my coding abilities I have not augmented the code to
fix the errors.  
