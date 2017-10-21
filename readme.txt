--------------------------------
		PROJECT
--------------------------------

Assignment 3
CSC 254 
Fall 2017
University of Rochester 



--------------------------------
		NAMES
--------------------------------

Luka Sherman 
lsherma5@u.rochester.edu

Nathan Conroy 
nconroy1@u.rochester.edu



--------------------------------
		RUN INSTRUCTIONS
--------------------------------

1. run "ocaml" in terminal to enter OCaml interpretor 
2. run "#use [full path of translator.ml file] ;;" 
3. run "translate test1", "translate test2", "translate test3", "translate test4", or "translate test5" + ";;"
4. the C code will print to stdout, copy it, paste it in a new C file, compile and run
5. the translate function returns 2 strings, the unused variables, and the C code



--------------------------------
		DESCRIPTION
--------------------------------


The assignment was to create a compiler "translator" in OCaml for the calculator language that generated C. We used the parser generator and driver given to us that builds an explicit parse tree. We then converted the parse tree to a syntax tree and recursively got the translation. 

The code has a tuple variable list "ast_varList", with the names of the variables and an integer. When the integer is set to 1 it means the variable has been used in an expression, when it is 0 it is unused. We use this code to return a list of unused variables at the end, as well as initialize the first instance of a variable with an "int " before it in the C code. 

We have different translator methods for different types of parse tree nodes. We used match statements in each of these methods for all of the different productions, to get the syntax tree. To get the C translation, we have recursive methods for each type of command. We concatenate the C syntax inbetween the variables and syntax tree nodes, so it recursively fills in the C translation. 

The C code catches several types of dynamic errors, and prints corresponding error messages. It detects unexpected end of input, non-numeric input, and dividing by zero. We did this by appending some default code to the beginning of the C code. We wrote getInt() and putInt() functions to get and print input. The getInt() method contains code to check for non-numeric input, and the EOF when expecting user input. It breaks and prints a message to the user. We also wrote a custom divide() function, that checks that ther is no dividing by zero.  

We did not write error handling for the use of uninitialized variables. We also did not write special features. 

We wrote several test programs "test1", "test2", "test3", "test4", and "test5" that are valid syntax trees, because we have already ran them through the syntax tree generator we wrote in part 1. 

or the person who has to understand the insides of your code, you may need to describe your choice of modularization (abstractions), data structures, and algorithms.  Be sure to explain anything you did that is likely to be different from what other students may have done, and justify any design decisions for which the rationale isn’t immediately clear.  


--------------------------------
		SAMPLE OUTPUT
--------------------------------

# translate test4;;

stdout:

//C CODE:

#include <stdio.h>
#include <stdlib.h>

int getint() { int a; char ch; if(scanf("%d", &a) == 0) { printf("Error: cannot enter non-numeric input.\n"); exit(1); } else if(scanf("%c", &ch) == EOF) { printf("Error: unexpected end of input.\n"); exit(1); } return a; }
void putint(int a) { printf("%d\n", a); }
int divide(int x, int y) { if(y == 0) { printf("Error: cannot divide by 0.\n"); exit(1); } return x / y; }

int main() {
int a = getint();
int b = 3;
int c = divide(3, (a - 1));
a = c;
c = 1;
int d = (c + 3);
putint (c);
}

returned by translate function:
- : string * string =
("b d ",
 "//C CODE:\n\n#include <stdio.h>\n#include <stdlib.h>\n\nint getint() { int a; char ch; if(scanf(\"%d\", &a) == 0) { printf(\"Error: cannot enter non-numeric input.\\n\"); exit(1); } else if(scanf(\"%c\", &ch) == EOF) { printf(\"Error: unexpected end of input.\\n\"); exit(1); } return a; }\nvoid putint(int a) { printf(\"%d\\n\", a); }\nint divide(int x, int y) { if(y == 0) { printf(\"Error: cannot divide by 0.\\n\"); exit(1); } return x / y; }\n\nint main() {\nint a = getint();\nint b = 3;\nint c = divide(3, (a - 1));\na = c;\nc = 1;\nint d = (c + 3);\nputint (c);\n}\n")