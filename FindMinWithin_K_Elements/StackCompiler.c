#include "StackCompiler.h"

//Compare 2 natural numbers (or return 1st number if 2nd number is '-1')
int Compare(int numA, int numB) {
	if (numB > 0)
		return min(numA, numB);
	return numA;
}

//Main function on the work with the Stack (created by Maxim)
int StackWorker(int arraySize, int lengthOfSubSegments, int *Array) {
	//TempStack - Temporary stack
	//MinFromStart - Stack with numbers sorted from the start
	//MinFromEnd - Stack with numbers sorted from the end
	Stack* TempStack = NULL, * MinFromStart = NULL, * MinFromEnd = NULL;
	int minimal;
	for (int i = 0; i < arraySize; i++) {
		//For the case when k == 1
		if (lengthOfSubSegments == 1)
			printf_s("%d ", Array[i]);
		else {
			//Store in TempStack
			if (!(push(&TempStack, Array[i])))
				return PUSH_ERROR;
			//First cycle
			if (MinFromEnd == NULL) {
				//Waiting until the end of the block
				if (i == lengthOfSubSegments - 2)
					//Fill up MinFromEnd while emptying TempStack
					while (top(TempStack) >= 0) {
						minimal = Compare(pop(&TempStack), top(MinFromEnd));
						if (!(push(&MinFromEnd, minimal)))
							return PUSH_ERROR;
					}
			}
			else {
				//Adding number from TempStack to MinFromStart
				minimal = Compare(top(TempStack), top(MinFromStart));
				if (!(push(&MinFromStart, minimal)))
					return PUSH_ERROR;
				//Outputting minimal between top numbers from Stacks MinFromStart & MinFromEnd
				minimal = Compare(pop(&MinFromEnd), top(MinFromStart));
				printf_s("%d ", minimal);
				//Fill up Stack MinFromEnd if empty (parallel process: emptying Stack MinFromStart)
				if (top(MinFromEnd) < 0) {
					clear(MinFromStart);
					MinFromStart = NULL;
					while (top(TempStack) >= 0) {
						minimal = Compare(pop(&TempStack), top(MinFromEnd));
						if (!(push(&MinFromEnd, minimal)))
							return PUSH_ERROR;
					}
				}
			}
		}
	}
	if (top(TempStack) >= 0) clear(TempStack);
	if (top(MinFromEnd) >= 0) clear(MinFromEnd);
	if (top(MinFromStart) >= 0) clear(MinFromStart);
	return 0;
}

//Main function on the work with the Stack (created by Maxim's father)
void StackWorker2(int arraySize, int lengthOfSubSegments, int* Array) {
	Stack* MinFromEnd = NULL, * Temp = NULL;
	int minFromStart = 0;
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
		clear(MinFromEnd);
	if (top(Temp) >= 0)
		clear(Temp);
}