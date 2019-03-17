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
int fibonacci(int n, int cache[])
{
	if (cache[n] >= 0) return cache[n];

	cache[n] = fibonacci(n-1, cache) + fibonacci(n-2, cache);
	return cache[n];
}

int main()
{
	int result, i, n = 40;
	int cache[n + 1];

	for (i = 0; i <=n; i++) {
		cache[i] = -1;
	}

	cache[0] = 0;
	cache[1] = 1;
	for( i = 0; i <=n; i++ ) {
		result = fibonacci(i, cache);
		printf("fibonacci(%d) = %d\n", i, result);
	}
	return 0;
}
