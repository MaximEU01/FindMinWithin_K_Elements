#ifndef STACK
#define STACK

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct List {
	int number;
	struct List* next;
} Stack;

//Putting the number in the stack
int push(Stack**, int);
//Taking the number out of stack
int pop(Stack**);
//Looking at the first number in the stack (returns -1, if nothing is there)
int top(const Stack*);
//Freeing up the memory used for the Stack
void clear(Stack*);

#endif