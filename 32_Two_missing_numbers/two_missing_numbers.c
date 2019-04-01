/*
 * Given an array containing all the numbers from 1 to n
 * except two, find the two missing numbers.
 * E.g.
 * missing({4, 2, 3}] => {1, 5}
 */

#include<stdio.h>
int one_missing(int arr[], int len)
{
	int i;
	int total_xor = 0;
	int arr_xor = 0;

	for (i = 1; i <= len + 1; i++)
		total_xor ^= i;

	for (i = 0; i < len; i++)
		arr_xor ^= arr[i];

	return total_xor ^ arr_xor;
}

void two_missing(int arr[], int len, int *missing)
{
	int i, size = len + 2, pivot = 0;
	long total_sum = 0;
	long arr_sum = 0;
	long total_left_xor = 0, total_right_xor = 0;
	long arr_left_xor = 0, arr_right_xor = 0;

	// 1 + 2 + 3 + ... N - 1 + N = N*(N + 1)/2
	total_sum = size * (size + 1)/2;

	for (i = 0; i < len; i++)
		arr_sum += arr[i];

	pivot = (total_sum - arr_sum)/2;

	for (i = 1; i <= pivot; i++)
		total_left_xor ^= i;
	for (i = pivot + 1; i <= size; i++)
		total_right_xor ^= i;

	printf("TOTAL LEFT XOR %d, TOTAL RIGHT XOR %d\n", total_left_xor, total_right_xor);
//#if 0
	for (i = 0; i < len && arr[i] <= pivot; i++) {
			printf("1. Pivot %d, arr %d\n", pivot, arr[i]);
			arr_left_xor ^= arr[i];
	}
	printf("arr 2 %d, pivot %d, len %d\n", arr[2], pivot, len);
	for (i = 0; i < len && arr[i] > pivot; i++)
		printf("ARRAY %d ", arr[i]);
	for (i = 0; i < len && arr[i] > pivot; i++) {
			printf("2. Pivot %d, arr %d\n", pivot, arr[i]);
			arr_right_xor ^= arr[i];
	}
//#endif
#if 0
	for (i = 0; i < len; i++) {
		if (arr[i] <= pivot) {
			printf("1. Pivot %d, arr %d\n", pivot, arr[i]);
			arr_left_xor ^= arr[i];
		} else {
			printf("2. Pivot %d, arr %d\n", pivot, arr[i]);
			arr_right_xor ^= arr[i];
		}
	}
#endif
	missing[0] = arr_left_xor ^ total_left_xor;
	missing[1] = arr_right_xor ^ total_right_xor;
	printf("MISSING[0] %d, MISSING [1] %d\n", missing[0], missing[1]);
}

int main()
{
	int arr[] = {2, 3, 4}, *missing;
	int len_arr = sizeof(arr)/sizeof(arr[0]), i;

	for (i = 0; i < len_arr; i++)
		printf("%d ", arr[i]);
	printf("\nOne missing: %d\n", one_missing(arr, len_arr));
	two_missing(arr, len_arr, missing);
	printf("Two missing: %d, %d\n", missing[0], missing[1]);
}
