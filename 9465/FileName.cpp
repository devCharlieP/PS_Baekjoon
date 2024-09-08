#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

void func()
{
	int n;
	cin >> n;

	vector<vector<int>> map(2, vector<int>(n));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	if (n == 1)
	{
		cout << max(map[0][0], map[1][0]) << endl;
		return;
	}

	vector<vector<int>> dp(2, vector<int>(n));

	dp[0][0] = map[0][0];
	dp[1][0] = map[1][0];
	dp[0][1] = dp[1][0] + map[0][1];
	dp[1][1] = dp[0][0] + map[1][1];

	for (int j = 2; j < n; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			int num = max(dp[0][j - 2], dp[1][j - 2]);
			int maxi;

			if (i == 0)
			{
				maxi = max(num, dp[i + 1][j - 1]);
			}
			else
			{
				maxi = max(num, dp[i - 1][j - 1]);
			}

			dp[i][j] = maxi + map[i][j];
		}
	}

	cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		func();
	}

	return 0;
}