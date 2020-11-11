#pragma once
#ifndef ARRAY
#define ARRAY

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct List {
	int number;
	struct List* next;
} Stack;

#endif