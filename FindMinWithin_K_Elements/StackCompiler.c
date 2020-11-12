#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

#include "Main.h"

//Basic Stack commands
void push(Stack **S, int num) {
	Stack* temp = malloc(sizeof(Stack));
	if (temp == NULL)
		exit(STACK_OVERFLOW);
	temp->number = num;
	temp->next = *S;
	*S = temp;
}

int pop(Stack** S) {
	Stack* out;
	int num;
	if (*S == NULL)
		exit(STACK_UNDERFLOW);
	out = *S;
	*S = (*S)->next;
	num = out->number;
	free(out);
	return num;
}

int top(const Stack* S) {
	if (S == NULL)
		return -1;
	return S->number;
}

//Freeing up the memory used for the Stack
void makenull(Stack* S) {
	struct List* p;
	while (S->next) {
		p = S->next;
		S->next = p->next;
		free(p);
	}
}

//Main function on the work with the Stack (created by Maxim)
void StackWorker(int arraySize, int lengthOfSubSegments, int *Array) {
	//TempStack - Temporary stack; MinFromStart - Stack with numbers sorted from the start; MinFromEnd - Stack with numbers sorted from the end
	Stack* TempStack = NULL, * MinFromStart = NULL, * MinFromEnd = NULL;
	int minF = 0;
	printf_s("\nThe answer is:\n");
	for (int i = 0; i < arraySize; i++) {
		//For the case when k == 1
		if (lengthOfSubSegments == 1)
			printf_s("%d ", Array[i]);
		else {
			//Store in TempStack
			push(&TempStack, Array[i]);
			//First cycle
			if (MinFromEnd == NULL) {
				//Waiting until the end of the block
				if (i % (lengthOfSubSegments - 1) == (lengthOfSubSegments - 2))
					//Fill up MinFromEnd while emptying TempStack
					while (top(TempStack) >= 0) {
						minF = pop(&TempStack);
						if (top(MinFromEnd) >= 0)
							minF = min(minF, top(MinFromEnd));
						push(&MinFromEnd, minF);
					}
			}
			else {
				//Process of adding number from TempStack to MinFromStart
				minF = top(TempStack);
				if (top(MinFromStart) >= 0)
					minF = min(minF, top(MinFromStart));
				push(&MinFromStart, minF);
				//Outputting minimal between top numbers from Stacks MinFromStart & MinFromEnd
				minF = pop(&MinFromEnd);
				printf_s("%d ", (top(MinFromStart) < minF) ? top(MinFromStart) : minF);
				//Fill up Stack MinFromEnd if empty (parallel process: emptying Stack MinFromStart)
				if (top(MinFromEnd) < 0)
					while (top(TempStack) >= 0) {
						if(top(MinFromStart) >= 0)
							minF = pop(&MinFromStart);
						minF = pop(&TempStack);
						if (top(MinFromEnd) >= 0)
							minF = min(minF, top(MinFromEnd));
						push(&MinFromEnd, minF);
					}
			}
		}
	}
	if (top(TempStack) >= 0) makenull(TempStack);
	if (top(MinFromEnd) >= 0) makenull(MinFromEnd);
	if (top(MinFromStart) >= 0) makenull(MinFromStart);
	//free(Array); //Uncomment if 2nd function is not being used
}

//Main function on the work with the Stack (created by Maxim's father)
void StackWorker2(int arraySize, int lengthOfSubSegments, int* Array) {
	Stack* MinFromEnd = NULL, * Temp = NULL;
	int minFromStart = 0;
	printf_s("\nThe answer is:\n");
	for (int i = 0; i < arraySize; i++) {
		//For the case when k == 1
		if (lengthOfSubSegments == 1)
			printf_s("%d ", Array[i]);
		else {
			if (i % (lengthOfSubSegments - 1) == 0)
				minFromStart = Array[i];
			else
				minFromStart = min(Array[i], minFromStart);
			//Putting new number in Stack Temp
			push(&Temp, Array[i]);
			//Outputting minimal of number minFromStart and the number pulled out of Stack MinFromEnd
			if ((i + 1) >= lengthOfSubSegments) {
				printf_s("%d ", min(minFromStart, top(MinFromEnd)));
				pop(&MinFromEnd);
			}
			if ((i + 1) % (lengthOfSubSegments - 1) == 0 || i == (arraySize - 1)) {
				//Filling up Stack MinFromEnd with the number pulled out of Stack Temp
				while (top(Temp) >= 0) {
					if (top(MinFromEnd) >= 0) {
						push(&MinFromEnd, min(top(Temp), top(MinFromEnd)));
						pop(&Temp);
					}
					else
						push(&MinFromEnd, pop(&Temp));
				}
			}
		}
	}
	if (top(MinFromEnd) >= 0)
		makenull(MinFromEnd);
	if (top(Temp) >= 0)
		makenull(Temp);
	free(Array);
}