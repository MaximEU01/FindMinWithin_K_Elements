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

//Main function on the work with the Stack
void StackWorker(int arraySize, int lengthOfSubSegments, int *Array) {
	//In - Temporary stack; MinS - Stack with numbers sorted from the start; MinF - Stack with numbers sorted from the end
	Stack* In = NULL, * MinS = NULL, * MinF = NULL;
	int minF = 0;
	printf_s("\nThe answer is:\n");
	for (int i = 0; i < arraySize; i++) {
		//For the case when k == 1
		if (lengthOfSubSegments == 1) {
			printf_s("%d ", Array[i]);
		}
		else {
			//
			push(&In, Array[i]);
			if (MinF == NULL) {
				if (i % (lengthOfSubSegments - 1) == (lengthOfSubSegments - 2))
					while (top(In) >= 0) {
						minF = pop(&In);
						if (top(MinF) >= 0)
							minF = min(minF, top(MinF));
						push(&MinF, minF);
					}
			}
			else {
				minF = top(In);
				if (top(MinS) >= 0)
					minF = min(minF, top(MinS));
				push(&MinS, minF);
				minF = pop(&MinF);
				printf_s("%d ", (top(MinS) < minF) ? top(MinS) : minF);
				if (top(MinF) < 0)
					while (top(In) >= 0) {
						if(top(MinS) >= 0)
							minF = pop(&MinS);
						minF = pop(&In);
						if (top(MinF) >= 0)
							minF = min(minF, top(MinF));
						push(&MinF, minF);
					}
			}
		}
	}
	if (top(In) >= 0)
		makenull(In);
	if (top(MinF) >= 0)
		makenull(MinF);
	if (top(MinS) >= 0)
		makenull(MinS);
	free(Array);
}


/*
Code_by_dad

void StackWorker2(int arraySize, int lengthOfSubSegments, int* Array) {
	Stack* B = NULL, * C = NULL, * Temp = NULL;

	for (int i = 0; i < arraySize; i++)
	{
		printf_s("\n%d ", i);
		//положить в стек Б минимум из него и нового элемента
		push(&B, min(Array[i], top(B)));

		//положить в стек Врем новый элемент
		push(&Temp, Array[i]);

		if (i % (2 * (lengthOfSubSegments - 1)) || i == (arraySize - 1))
		{

			//на основании стека Врем создаем стек С с очисткой стека Врем
			while (top(Temp) >= 0) {
				printf_s("While %d ", i);
				if (top(C) >= 0)
					push(&C, min(pop(&Temp), top(C)));
				else
					push(&C, pop(&Temp));
			}

			//выводим минимумы по стекам Б и С с их очисткой
			while (top(C) >= 0)
				printf_s("Ans %d ", min(pop(&B), pop(&C)));
		}
	}
}
*/