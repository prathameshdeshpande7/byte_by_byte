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

#if 0
double median(int a[], int len_a, int b[], int len_b)
{
    int *ptr_a, *ptr_b;
    int i, j, k;
    double med = 0;
    int c[len_a + len_b];

    ptr_a = a, ptr_b = b;

    for( i = 0, j = 0, k = 0; i < len_a, j < len_b;) {
        if( a[i] <= b[j] ) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while( i < len_a) {
        c[k++] = a[i++];
    }

    while( j < len_b) {
        c[k++] = b[j++];
    }

    med = ((double)c[k/2 - 1] + (double)c[k/2]) / 2;
    return med;
}
#endif

#define COUNT_OF(elem)  (sizeof(elem) / sizeof(elem[0]))
double median(int a[], int len_a, int b[], int len_b)
{
    int *ptr_a, *ptr_b;
    double med = 0;
    int c[len_a + len_b], k = 0, i;

    for( ptr_a = a, ptr_b = b; ptr_a < &a[COUNT_OF(a)] && ptr_b < &b[COUNT_OF(b)];) {
        if( *ptr_a <= *ptr_b ) {
            c[k++] = *ptr_a++;
        } else {
            c[k++] = *ptr_b++;
        }
    }

    printf("COUNT %d, %d\n", COUNT_OF(a), COUNT_OF(b));
    while( ptr_a < &a[COUNT_OF(a)] ) {
        c[k++] = *ptr_a++;
    }

    while( ptr_b < &b[COUNT_OF(b)] ) {
        c[k++] = *ptr_b++;
    }

    for( i = 0; i < k; i++ ) {
        printf("c[%d] = %d\n", i, c[i]);
    }

    med = ((double)c[k/2 - 1] + (double)c[k/2]) / 2;
    return med;
}

int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    int b[6] = {0, 0, 0, 0, 10, 10};
    int length_a = sizeof(a) / sizeof(a[0]);
    int length_b = sizeof(b) / sizeof(b[0]);
    double med;
    int i, j;

    med = median(a, length_a, b, length_b);

    printf("a[] = {");
    for( i = 0; i < length_a; i++ ) {
        printf( "%d%s", a[i], (i == length_a - 1) ? "}" : ", " );
    }

    printf("\nb[] = {");
    for( j = 0; j < length_b; j++ ) {
        printf( "%d%s", b[j], (j == length_b - 1) ? "}" : ", " );
    }
    printf("\nMedian of arrays a[] and b[] is %f\n", med);
    return 0;
}
