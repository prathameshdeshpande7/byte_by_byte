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
	if (n <= 1) return n;
	return fibonacci(n-1) + fibonacci(n-2);
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
