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

//Main function on the work with the Stack
void StackWorker(int n, int k, int *A) {
	struct Stack* First = NULL, *Current = NULL, *Last = NULL, *MovingFirst = NULL;
	int counterStack = 0;
	printf_s("\nYour answer:\n");
	//For the case when number K equals 1
	if (k == 1) {
		for (counterStack = 0; counterStack < n; counterStack++)
			printf_s("%d ", A[counterStack]);
		free(A);
		return;
	}
	struct Stack *MinFirst = NULL, * MinCurr = NULL, *MinLast = NULL;
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
			Current = First;
			for (int j = 0; j < counterStack; j++) {
				if (j < (counterStack / (k - 1)) * (k - 1))
					Current = Current->Next;
				else {
					if (Last->number < Current->number)
						Current->number = Last->number;
					Current = Current->Next;
				}
			}
			counterStack++;
		}
		//Compare if the count of elements in the Stack equals/above our number K
		if (k <= counterStack) {
			if (i % (k - 1) == 0)
				if (MinFirst != NULL) {
					ClearStack(MinFirst);
					MinFirst = NULL;
				}
			MinCurr = malloc(sizeof(struct Stack));
			MinCurr->number = Last->number;
			MinCurr->Next = NULL;
			if (MinFirst == NULL) {
				MinFirst = MinCurr;
				MinLast = MinCurr;
			}
			else {
				MinLast->Next = MinCurr;
				if (MinLast->number < MinCurr->number)
					MinCurr->number = MinLast->number;
				MinLast = MinCurr;
			}
			printf_s("%d ", (MovingFirst->number < MinLast->number) ? MovingFirst->number : MinLast->number);
			if(MovingFirst->Next)
				MovingFirst = MovingFirst->Next;
		}
	}
	free(A);
	ClearStack(MinFirst);
	ClearStack(First);
}