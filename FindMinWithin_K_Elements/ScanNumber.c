//Extra function of getting the number
#include "Main.h"

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
	//(topLimit == 0) is for the case when you choose the size of an array
	if (topLimit == 0) {
		//Checking for lower limit
		if (requestedNumber <= 0) {
			printf_s("I accept only natural numbers, please try again...\n");
			requestedNumber = ScanNumber(topLimit);
		}
	}
	else {
		//Checking for lower limit
		if (requestedNumber <= 0) {
			printf_s("I accept only natural numbers, please try again...\n");
			requestedNumber = ScanNumber(topLimit);
		}
		//Checking for upper limit
		if (topLimit < requestedNumber) {
			printf_s("Number must me in range [1; %d], please try again...\n", topLimit);
			requestedNumber = ScanNumber(topLimit);
		}
	}
	return requestedNumber;
}