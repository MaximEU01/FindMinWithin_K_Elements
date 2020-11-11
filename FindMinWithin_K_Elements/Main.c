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

#define MINIM 1
#define MAXED 9

//Writing out starting words & getting info
void InfoInput() {
	int arraySize, lengthOfSubSegments, currentNumber;
	printf_s("Program name: FindMinWithin_K_Elements\n\n");
	//Inputting number N
	printf_s("How many natural numbers will be in the array?\n");
	arraySize = ScanNumber(0);
	//Inputting number K
	printf_s("What is the length of sub-segments?\n");
	lengthOfSubSegments = ScanNumber(arraySize);
	int *number = malloc(sizeof(int)*arraySize);
	//Filling up an array A
	printf_s("Input %d numbers:\n", arraySize);
	for (currentNumber = 0; currentNumber < arraySize; currentNumber++) {
		number[currentNumber] = ScanNumber(0);
	}
	StackWorker(arraySize, lengthOfSubSegments, number);
}

int main() {
	InfoInput();
	return 0;
}