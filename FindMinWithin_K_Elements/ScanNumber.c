#include "Main.h"

int NaturalCheck(int number) {
	if (number <= 0) {
		printf_s("I accept only natural numbers, please try again...\n");
		return 0;
	}
	return 1;
}

int RangeCheck(int number, int topLim) {
	if (topLim < number) {
		printf_s("Number must be in range [1; %d], please try again...\n", topLim);
		return 0;
	}
	return 1;
}

//Function of manual input of natural number
int ScanNumber(int topLimit) {
	//Initialising the input number
	int requestedNumber;
	//Initialising dump parameter
	char dumper[256];
	while (!scanf_s("%d", &requestedNumber)) {
		printf_s("Input the number, please try again...\n");
		//"Clearing" the buffer
		gets(dumper);
	}
	//(topLimit == 0) is for the case when you choose the size of an array & its natural numbers
	if (topLimit == 0) {
		//Checking for lower limit
		if (!(NaturalCheck(requestedNumber)))
			requestedNumber = ScanNumber(topLimit);
	}
	else {
		//Checking for lower limit
		if (!(NaturalCheck(requestedNumber)))
			requestedNumber = ScanNumber(topLimit);
		//Checking for upper limit
		if (!(RangeCheck(requestedNumber, topLimit)))
			requestedNumber = ScanNumber(topLimit);
	}
	return requestedNumber;
}