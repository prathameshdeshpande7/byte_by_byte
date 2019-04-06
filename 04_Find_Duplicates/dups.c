/*
 * Given an array of integers where each value
 * 1 <= x <= len(array), write a function that
 * finds all duplicates in the array.
 *
 * E.g.
 * dups({1, 2, 3}] = {}
 * dups({1, 2, 2}] = {2}
 * dups({3, 3, 3}] = {3}
 * dups({2, 1, 2, 1}] = {1, 2}
 */

#include<stdio.h>
#include<math.h>
/*
 * Encode information about the array in
 * the array itself. For example, {2, 1, 2, 1}
 * let index = arr[i] - 1, flip the sign of value at index.
 *
 * if we have already seen the entry its encoding
 * info will be negative.
 *
 * Brute force:	Time  - O(N^2)
 *
 * Hash:	Time  - O(N)
 * 		Space - O(N)
 *
 * Sort:	Time  - O(N log N)
 * 		Space - O(1)
 *
 * Encoding:	Time  - O(N)
 * 		Space - O(1)
 */
void dups(int a[], int len)
{
	/* TODO: store result in hash table for uniqueness */
	int i, index, unique[len], j = 0;

	for (i = 0; i < len; i++) {
		index = abs(a[i]) - 1;
		if (a[index] > 0)
			a[index] = -a[index];
		else
			 unique[j++] = abs(a[i]);
	}

	// restore all negative values to their original value
	for (i = 0; i < len; i++)
		a[i] = abs(a[i]);

	for (i = 0; i < j; i++)
		printf("%d ", unique[i]);
	printf("\n");
}

int main()
{
	int arr[] = {2, 2, 2, 1}, i, *unique;
	int len_arr = sizeof(arr) / sizeof(arr[0]);

	printf("Array: ");
	for (i = 0; i < len_arr; i++)
		printf("%d ", arr[i]);

	printf("\nDuplicates: ");
	dups(arr, len_arr);
}
