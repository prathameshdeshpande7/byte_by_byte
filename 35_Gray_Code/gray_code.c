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

#define MASK_LAST_BIT	0x1

int gray(long long int a, long long int b)
{
	long long int xor = a ^ b;

	// if both integers are same, return false as gray code
	// since there is no difference of bits
	if (xor == 0)
		return 0;

	while(xor > 0) {
		if (xor % 2 == 1 && xor >> 1)
			return 0;
		xor >>= 1;
	}

	return 1;
}

int main()
{
	//long long int a = 15, b = 16;
	long long int a = 32767, b = 32767;
	//long long int a = 2, b = 1;
	//long long int a = 1, b = 0;
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
