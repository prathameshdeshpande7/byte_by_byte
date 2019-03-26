/*
 * Given two integers, write a function
 * to determine whether or not their binary
 * representations differ by a single bit.
 *
 * E.g.
 *
 * gray(0, 1) = true
 * gray(1, 2) = false
 */

#include <stdio.h>
#include "print_binary.h"

int gray(int a, int b)
{
	return 1;
}

int main()
{
	long long int a = 15, b = 16;
	int is_gray = -1;

	is_gray = gray(a, b);
	printf("a: %llu, binary: " PRINT_BINARY_PATTERN_INT64"\n", a, PRINT_BYTE_TO_BINARY_INT64(a));
	printf("b: %llu, binary: " PRINT_BINARY_PATTERN_INT64"\n", b, PRINT_BYTE_TO_BINARY_INT64(b));
	if (is_gray)
		printf("Having gray code\n");
	else
		printf("Not having gray code\n");

	return 0;
}
