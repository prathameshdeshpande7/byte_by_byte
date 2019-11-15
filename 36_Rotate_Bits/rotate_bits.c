/*
 * ● Question : Given a number, write a function to rotate the bits (ie circular shift).
 * ● Eg.
 *
 * rotate(0xFFFF0000, 8) = 0x00FFFF00
 * rotate(0x13579BDF, 12) = 0xBDF13579
 * rotate(0b10110011100011110000111110000000, 17) =
 * 0b00011111000000010110011100011110
 */

#include<stdio.h>
#include "print_binary.h"

int left_rotate(int num, int shift)
{
	return ( (num << shift) | (num >> 32 - shift) );
}

int right_rotate(int num, int shift)
{
	return ( (num >> shift) | (num << 32 - shift) );
}

int main()
{
	int n = 16;
	int d = 2;
	int left_n = 0, right_n = 0;

	printf("Number: %llu, shift: %d\n", n, d);

	left_n = left_rotate(n, d);
	printf("Left rotation: %llu " PRINT_BINARY_PATTERN_INT32"\n", left_n, PRINT_BYTE_TO_BINARY_INT32(left_n));

	right_n = right_rotate(n, d);
	printf("Right Rotation: %llu " PRINT_BINARY_PATTERN_INT32"\n", right_n, PRINT_BYTE_TO_BINARY_INT32(right_n));
	return 0;
}
