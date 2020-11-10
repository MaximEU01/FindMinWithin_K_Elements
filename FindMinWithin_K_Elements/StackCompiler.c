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

//Freeing up the memory used fo the Stack
void ClearStack(struct Stack* H) {
	struct Stack* Current = H;
	while (Current != NULL) {
		Current = Current->Next;
		free(H);
		H = Current;
	}
}

//Finding minimal number in sub-segment of K elements
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

//Main function on the work with the Stack
void StackWorker(int n, int k, int *A) {
	struct Stack* First = NULL, *Current = NULL, *Last = NULL, *MovingFirst = NULL;
	int counterStack = 0;
	printf_s("\nYour answer:\n");
	//For the case when number K equals 1
	if (k == 1) {
		for (counterStack = 0; counterStack < n; counterStack++)
			printf_s("%d ", A[counterStack]);
		return;
	}
	for (int i = 0; i < n; i++) {
		Current = malloc(sizeof(struct Stack));
		Current->number = A[i];
		Current->Next = NULL;
		//Creating 1st element in the Stack
		if (First == NULL) {
			First = Current;
			MovingFirst = First;
			Last = First;
			counterStack = 1;
		}
		//Adding new elements to our Stack
		else {
			Last->Next = Current;
			Last = Current;
			counterStack++;
		}
		//Compare if the count of elements in the Stack equals/above our number K
		if (k <= counterStack) {
			printf_s("%d ", MinInStack(MovingFirst));
			if(MovingFirst->Next)
				MovingFirst = MovingFirst->Next;
		}
	}
	ClearStack(First);
}