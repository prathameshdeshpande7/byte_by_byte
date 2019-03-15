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

int c[20];

double median(int a[], int len_a, int b[], int len_b)
{
    int *ptr_a, *ptr_b;
    int i, j, k;
    double med = 0;

    ptr_a = a, ptr_b = b;

    for( i = 0, j = 0, k = 0; i < len_a, j < len_b;) {
        if( a[i] <= b[j] ) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    for( i = 0; i < k; i++) {
        printf("c[%d] = %d, k = %d\n", i, c[i], k);
    }
    med = (c[k/2 - 1] + c[k/2]) / 2;
    printf("Target c[k/2 - 1] %d and c[k/2] %d = %d\n", c[k/2 - 1], c[k/2], med);
    return med;
}

int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    int b[6] = {0, 0, 0, 0, 10, 10};
    int length_a = sizeof(a) / sizeof(a[0]);
    int length_b = sizeof(b) / sizeof(b[0]);
    double med;

    med = median(a, length_a, b, length_b);

    printf("Median of arrays a[] and b[] is %f\n", med);
    return 0;
}
