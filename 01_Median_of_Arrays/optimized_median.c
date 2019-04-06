/*
 * ● Question : Find the median of two sorted arrays.
 * ● Eg.
 * arr1 = [1, 3, 5]
 * arr2 = [2, 4, 6]
 * median(arr1, arr2) = 3.5
 *
 * arr1 = [1, 2, 3, 4, 5, 6]
 * arr2 = [0, 0, 0, 0, 10, 10]
 * median(arr1, arr2) = 2.5
 */

#include <stdio.h>

#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#define MIN(a, b)  ((a) < (b) ? (a) : (b))

double get_median( int array[], int start, int size )
{
	if( size % 2 == 0 )
		return ((double)array[ start + size/2 ] +
			(double)array[ start + size/2 - 1 ]) / 2.0f;
	return (double)array[ start + size/2 ];
}

double median( int a[], int start_a, int end_a, int b[], int start_b, int end_b )
{
	int size_a, size_b, it;
	double median_a, median_b;

	size_a = end_a - start_a + 1;
	size_b = end_b - start_b + 1;

	// If only one element then calculate average and return
	if( size_a == 1 )
		return ( a[start_a] + b[start_b] ) / 2.;

	// If 2 elements in subarrays, then pick maximum from first
	// index of both arrays and minimum from last element of
	// both arrays, calculate average and return
	if( size_a == 2 )
		return ( MAX(a[start_a], b[start_b]) + MIN(a[end_a], b[end_b]) ) / 2.;

	median_a = get_median( a, start_a, size_a );
	median_b = get_median( b, start_b, size_b );
	if( median_a == median_b )
		return median_a;

	if( median_a > median_b )
		return median(a, start_a, (start_a + size_a/2),
			      b, (start_b + (size_b - 1)/2), end_b);
	return median(a, (start_a + (size_a - 1)/2), end_a,
		      b, start_b, (start_b + size_b/2));
}

int main()
{
	//int arr1[] = {1, 2, 3, 4, 5, 6};
	//int arr2[] = {0, 0, 0, 0, 10, 10};
	//int arr1[] = {1, 4, 8, 13, 16};
	//int arr2[] = {2, 5, 6, 11, 14};
	//int arr1[] = {0, 0, 0, 0, 0, 0, 0};
	//int arr2[] = {1, 1, 1, 1, 1, 1, 1};
	int arr1[] = {1, 3, 5};
	int arr2[] = {2, 4, 6};
	int len_arr1 = sizeof(arr1) / sizeof(arr1[0]);
	int len_arr2 = sizeof(arr2) / sizeof(arr2[0]);
	double med = 0.;
	int i, j;

	// Check for array length
	if( len_arr1 == 0 || len_arr2 == 0 )
		return -1;
	// Check if array lengths are same
	if( len_arr1 != len_arr2 )
		return -1;

	med = median( arr1, 0, len_arr1 - 1, arr2, 0, len_arr2 - 1 );

	printf("arr1[] = {");
	for( i = 0; i < len_arr1; i++ ) {
		printf( "%d%s", arr1[i], (i == len_arr1 - 1) ? "}" : ", " );
	}

	printf("\narr2[] = {");
	for( j = 0; j < len_arr2; j++ ) {
		printf( "%d%s", arr2[j], (j == len_arr2 - 1) ? "}" : ", " );
	}
	printf("\nMedian of arrays arr1[] and arr2[] is %f\n", med);

	return 0;
}
