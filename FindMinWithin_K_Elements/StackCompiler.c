#ifndef Array
#define Array

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

struct Stack {
	int number;
	struct Stack* Next;
} ;

#endif

void ClearStack(struct Stack* H) {
	struct Stack* Current = H;
	while (Current != NULL) {
		Current = Current->Next;
		free(H);
		H = Current;
	}
}

int MinInStack(struct Stack* Compare) {
	int minimal = Compare->number;
	Compare = Compare->Next;
	while (Compare != NULL) {
		if (minimal > Compare->number)
			minimal = Compare->number;
		Compare = Compare->Next;
	}
	return minimal;
}

void StackWorker(int n, int k, int *A) {
	struct Stack* First = NULL, *Current = NULL, *Last = NULL, *MovingFirst = NULL;
	int counterStack = 0;
	printf_s("\nYour answer:\n");
	for (int i = 0; i < n; i++) {
		Current = malloc(sizeof(struct Stack));
		Current->number = A[i];
		Current->Next = NULL;
		if (First == NULL) {
			First = Current;
			MovingFirst = First;
			Last = First;
			counterStack = 1;
		}
		else {
			Last->Next = Current;
			Last = Current;
			counterStack++;
		}
		if (k <= counterStack) {
			printf_s("%d ", MinInStack(MovingFirst));
			if(MovingFirst->Next)
				MovingFirst = MovingFirst->Next;
		}
	}
	ClearStack(First);
}