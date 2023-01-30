#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int>> vec(501, vector<int>(501));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> vec[i][j];
		}
	}

	vector<vector<int>> dp(501, vector<int>(501));
	dp[1][1] = vec[1][1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				dp[i][j] = vec[i][j] + dp[i - 1][j];
			}
			else if (j == i)
			{
				dp[i][j] = vec[i][j] + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = vec[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}
	}

	int res = -1;

	for (int i = 1; i <= n; i++)
	{
		res = max(res, dp[n][i]);
	}

	cout << res;

	return 0;
}