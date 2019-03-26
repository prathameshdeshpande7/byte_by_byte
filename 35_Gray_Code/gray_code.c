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
	int no_of_diff_bits = 0;

	while(a && b) {
		// Check for match of last bit of both integers
		if (a & MASK_LAST_BIT == b & MASK_LAST_BIT) {
			a >>= 1;
			b >>= 1;
		} else {
			no_of_diff_bits++;
			if (no_of_diff_bits > 1)
				return 0;	// false, no gray code
		}
	}

	if (a == 0)
		return ((b & (b - 1)) == 0) ? 1: 0;
	if (b == 0)
		return ((a & (a - 1)) == 0) ? 1: 0;
}

int main()
{
	//long long int a = 15, b = 16;
	long long int a = 1, b = 2;
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
