/*
 * 49. Fibonacci Number
 * Question : Given an integer n, write a function to compute the nth Fibonacci
 * number.
 * Eg.
 * fibonacci(1) = 1
 * fibonacci(5) = 5
 * fibonacci(10) = 55
 */
#include <stdio.h>
int fibonacci(int n)
{
	int n0, n1, n2, i;
	
	if (n <= 1) return n;

	n0 = 0;
	n1 = 1;

	for (i = 2; i <= n; i++) {
		n2 = n0 + n1;
		n0 = n1;
		n1 = n2;
	}
	return n2;
}

int main()
{
	int result, i, n = 40;

	for( i = 0; i <=n; i++ ) {
		result = fibonacci(i);
		printf("fibonacci(%d) = %d\n", i, result);
	}
	return 0;
}
