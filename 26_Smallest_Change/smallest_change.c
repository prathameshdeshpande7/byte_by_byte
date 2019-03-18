/*
 * Smallest Change
 * ● Question: Given an input amount of change x, write a function to determine the
 * minimum number of coins required to make that amount of change.
 * ● Eg. (using American coins $25, 10, 5, 1)
 * change(1) = 1
 * change(3) = 3
 * change(7) = 3
 * change(32) = 4
 */

#include <stdio.h>

int make_change(int change, int coins[], int n_coins)
{
	int i, result = 0, min_coins = 0;

	for (i = 0; i < n_coins; ) {
		if (result + coins[i] <= change) {
			result += coins[i];
			min_coins++;
			printf("[$%d] ", coins[i]);
		} else
			i++;
	}
	return min_coins;
}

int main()
{
	int coins[] = {25, 10, 5, 1};
	int n_coins = sizeof(coins)/sizeof(coins[0]);
	int min_coins, i;

	for (i = 0; i < 100; i++) {
		printf("Change(%d) = ", i);
		min_coins = make_change(i, coins, n_coins);
		printf(" (%d)\n", min_coins);
	}
	return 0;
}
