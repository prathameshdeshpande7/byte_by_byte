/*
 * Given two integers, write a function that
 * swaps them without using temporary variables
 */
#include <stdio.h>
void swap(int *a, int *b)
{

	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main()
{
	int a = 10, b = 15;

	printf("Before swap, a: %d, b: %d\n", a, b);
	swap(&a, &b);
	printf("After swap, a: %d, b: %d\n", a, b);

	return 0;
}

