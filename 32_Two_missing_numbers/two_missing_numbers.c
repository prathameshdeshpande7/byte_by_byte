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

int main()
{
	int arr[] = {2, 1, 4};
	int len_arr = sizeof(arr)/sizeof(arr[0]);

	printf("One missing: %d\n", one_missing(arr, len_arr));
}
