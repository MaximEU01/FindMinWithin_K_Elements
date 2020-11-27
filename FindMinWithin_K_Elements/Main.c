/*

Description:
	Given an array A of length N, consisting of natural numbers.

Task:
	Output mininum on all sub-segments of the array A of fixed length K.

Restrictions:
	Use stacks/queues;
	Minimal passes through stacks/queues.

Author: Maxim Uvarov (mix2013)

*/

#include "Main.h"

int main() {
	printf_s("Program name: Finding Minimum Within K Elements\n\n");
	//Inputting number N
	printf_s("How many natural numbers will be in the array?\n");
	int arraySize = ScanNumber(0);
	//Inputting number K
	printf_s("What is the length of sub-segments?\n");
	int lengthOfSubSegments = ScanNumber(arraySize);
	int* Array = (int*)malloc(sizeof(int) * arraySize);
	//Filling up an array A
	printf_s("Input %d numbers:\n", arraySize);
	for (int currentNumber = 0; currentNumber < arraySize; currentNumber++)
		Array[currentNumber] = ScanNumber(0);
	printf_s("\nMethod 1.");
	printf_s("\nThe answer is:\n");
	if (StackWorker(arraySize, lengthOfSubSegments, Array) < 0)
		return -100;
	/*
	printf_s("\n\nMethod 2.");
	printf_s("\nThe answer is:\n");
	StackWorker2(arraySize, lengthOfSubSegments, Array);
	*/
	free(Array);
	return 0;
}