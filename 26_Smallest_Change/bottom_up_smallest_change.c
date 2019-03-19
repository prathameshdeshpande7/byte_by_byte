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

int make_change(int change, int n_coins, int coins[], int cache[])
{
	int i, min_coins = 9999, curr_min_coins, j;

	for (i = 1; i <= change; i++) {
		min_coins = 9999;
		for (j = 0; j < n_coins; j++) {
			if (i - coins[j] >= 0) {
				curr_min_coins = cache[i - coins[j]] + 1;
				if (curr_min_coins < min_coins) {
					min_coins = curr_min_coins;
				}
			}
		}
		cache[i] = min_coins;
	}
	return min_coins;
}

int main()
{
	int coins[] = {1, 5, 25, 10};
	int n_coins = sizeof(coins)/sizeof(coins[0]);
	int min_coins, i;
	int cache[101] = {0};

	for (i = 95; i <= 100; i++) {
		printf("Change(%d) = ", i);
		min_coins = make_change(i, n_coins, coins, cache);
		printf(" (%d)\n", min_coins);
	}
	return 0;
}
