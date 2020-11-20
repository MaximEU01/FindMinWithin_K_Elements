#include "StackCommands.h"

//Putting the number in the stack
int push(Stack** S, int num) {
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	if (temp == NULL) {
		printf_s("Failed to fill the stack with new number, exiting...");
		return 0;
	}
	temp->number = num;
	temp->next = *S;
	*S = temp;
	return 1;
}

//Taking the number out of stack
int pop(Stack** S) {
	Stack* out;
	int num;
	if (*S == NULL) {
		printf_s("Failed to get number out of stack, exiting...");
		exit(-101);
	}
	out = *S;
	*S = (*S)->next;
	num = out->number;
	free(out);
	return num;
}

//Looking at the first number in the stack (returns -1, if nothing is there)
int top(const Stack* S) {
	if (S == NULL)
		return -1;
	return S->number;
}

//Freeing up the memory used for the Stack
void clear(Stack* S) {
	struct List* p;
	while (S->next) {
		p = S->next;
		S->next = p->next;
		free(p);
	}
}