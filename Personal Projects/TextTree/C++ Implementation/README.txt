
C++ Implementation (TextTree)

Brief:

Class header and implementation files and main driver for TextTree class.  

Detailed:

Class header and implementation files and main driver for TextTree class meant
to act as a prototype or test for the Java implementation of the TextTree class.
The TextTree class is a tree structure where any node many have any number of
child nodes and each one holds label and content strings.  The purpose is to
provide a structure which can hold textual data, the content, and to tie a
label or meaning to that data, its label, which is arranged hierarchically.

The main driver can be executed to test the TextTree by following the menu 
prompts.  The first (root) node can be added immediately but each subsequent 
node must be added have its parent specified by searching for its label then
adding.  If a parent is not specified it will be whatever it was for the 
most recent addition.
