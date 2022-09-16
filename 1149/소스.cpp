#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector <vector <int>> cost(N + 1, vector<int>(4));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> cost[i][j];
		}
	}

	vector <vector <int>> dp(N + 1, vector<int>(4));

	for (int i = 1; i <= 3; i++)
	{
		dp[1][i] = cost[1][i];
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (j == 1)
			{
				dp[i][j] = min(dp[i - 1][2] + cost[i][j], dp[i - 1][3] + cost[i][j]);
			}
			else if (j == 2)
			{
				dp[i][j] = min(dp[i - 1][1] + cost[i][j], dp[i - 1][3] + cost[i][j]);
			}
			else
			{
				dp[i][j] = min(dp[i - 1][1] + cost[i][j], dp[i - 1][2] + cost[i][j]);
			}
		}
	}

	int min = 987654321;

	for (int i = 1; i <= 3; i++)
	{
		if (min > dp[N][i])
		{
			min = dp[N][i];
		}
	}

	cout << min;

	return 0;
}