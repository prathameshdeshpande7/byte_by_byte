/*
 * Question: Given a 2D array of 0's and 1's
 * find the largest square subarray of all 1's
 */
#include<stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int square_subarray(int m, int n, int arr[][n], int cache[][n])
{
	int i, j, max = 0;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 || j == 0) {
				cache[i][j] = arr[i][j] ? 1: 0;
			} else if(arr[i][j]) {
				cache[i][j] = MIN(MIN(cache[i][j-1], cache[i-1][j]),
						  cache[i-1][j-1]) + 1;
			}
			max = MAX(max, cache[i][j]);
		}
	}
	return max;
}

int main()
{
	int arr[][4] = {0, 1, 0, 0,
			1, 1, 1, 0,
			0, 1, 1, 0};

	int arr1[][5] = {1, 1, 1, 1, 1,
			 1, 1, 1, 1, 0,
			 1, 1, 1, 1, 0,
			 1, 1, 1, 1, 0,
			 1, 0, 0, 0, 0};

	int arr2[][5] = {1, 1, 1, 1, 1,
			 1, 1, 1, 1, 0,
			 1, 1, 1, 1, 0,
			 0, 1, 1, 1, 0,
			 1, 0, 0, 0, 0};
	int len, m, n;
	m = sizeof(arr1)/sizeof(arr1[0]);
	n = sizeof(arr1[0])/sizeof(arr1[0][0]);
	printf("len m %d, n %d\n", m, n);

	int cache[][5] = {0};
	len = square_subarray(m, n, arr1, cache);
	printf("Max length of square submatrix: %d\n", len);
}
