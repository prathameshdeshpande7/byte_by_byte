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
	int i, min_coins = 0;

	if (change == 0) return 0;

	for (i = 0; i < n_coins; i++) {
		if (coins[i] <= change) {
			min_coins = make_change(change - coins[i], coins, n_coins);
			min_coins++;
			printf("[$%d] ", coins[i]);
		}
	}

	return min_coins;
}

int main()
{
	int coins[] = {6, 1, 10};
	int n_coins = sizeof(coins)/sizeof(coins[0]);
	int min_coins, i;

	for (i = 0; i <= 12; i++) {
		printf("Change(%d) = ", i);
		min_coins = make_change(i, coins, n_coins);
		printf(" (%d)\n", min_coins);
	}
	return 0;
}
