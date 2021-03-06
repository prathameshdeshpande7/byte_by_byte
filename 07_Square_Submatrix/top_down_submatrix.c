/*
 * Question: Given a 2D array of 0's and 1's
 * find the largest square subarray of all 1's
 */
#include<stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int subarray(int m, int n, int arr[][n], int i, int j, int cache[][n])
{
	if (i == m && j == n) return 0;

	if (!arr[i][j]) return 0;

	if (cache[i][j] > 0) return cache[i][j];

	cache[i][j] = 1 + MIN(MIN(subarray(m, n, arr, i + 1, j, cache),
		       subarray(m, n, arr, i, j + 1, cache)),
		       subarray(m, n, arr, i + 1, j + 1, cache));
	return cache[i][j];
}

int square_subarray(int m, int n, int arr[][n], int cache[][n])
{
	int i, j, max = 0;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (arr[i][j])
				max = MAX(max, subarray(m, m, arr, i, j, cache));
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
	m = sizeof(arr2)/sizeof(arr2[0]);
	n = sizeof(arr2[0])/sizeof(arr2[0][0]);
	printf("len m %d, n %d\n", m, n);

	int cache[][5] = {0};
	len = square_subarray(m, n, arr2, cache);
	printf("Max length of square submatrix: %d\n", len);
}
