// knapsack_algorith_DP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int sack[5][6];

int choose_max(int x, int y)
{
	return (x > y) ? x : y;
}

int knapsack(int n, int W, int value[], int weight[])
{
	if (n == 0 || W == 0)
	{
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (weight[i - 1] <= j)
			{
				sack[i][j] = choose_max(sack[i - 1][j], value[i - 1] + sack[i - 1][j - weight[i - 1]]);
			}
			else
			{
				sack[i][j] = sack[i - 1][j];
			}
		}
	}

	return sack[n][W];
}

int main()
{
	int weight[4] = {2, 1, 3, 2}, value[4] = { 12, 10, 20, 15 };

	int W = 5, n = 4;

	cout << knapsack(n, W, value, weight) << endl;

    return 0;
}

