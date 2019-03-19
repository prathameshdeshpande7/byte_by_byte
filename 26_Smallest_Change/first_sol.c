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

int make_change(int change, int coins[], int n_coins, int coins_req_for_change[])
{
	int i, min_coins = 9999, curr_min_coins;

	if (change == 0) return 0;

	if (coins_req_for_change[change] != 0) return coins_req_for_change[change];

	for (i = 0; i < n_coins; i++) {
		if (change - coins[i] >= 0) {
			curr_min_coins = make_change(change - coins[i], coins, n_coins, coins_req_for_change);
			if (curr_min_coins < min_coins) {
				min_coins = curr_min_coins;
			}
			printf("[$%d] ", coins[i]);
		}
	}

	coins_req_for_change[change] = min_coins + 1;
	return min_coins + 1;
}

int main()
{
	int coins[] = {1, 5, 25, 10};
	int n_coins = sizeof(coins)/sizeof(coins[0]);
	int min_coins, i;
	int coins_req_for_change[101] = {0};

	for (i = 95; i <= 100; i++) {
		printf("Change(%d) = ", i);
		min_coins = make_change(i, coins, n_coins, coins_req_for_change);
		printf(" (%d)\n", min_coins);
	}
	for (i=0; i < 101; i++)
		printf("coins_req_for_change[%d] = %d ", i, coins_req_for_change[i]);
	return 0;
}
