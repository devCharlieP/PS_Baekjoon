#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int mod = 10007;

	vector<vector<int>> dp(N + 1, vector<int>(10));

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
			}
		}
	}

	int res = 0;

	for (int i = 0; i < 10; i++)
	{
		res += dp[N][i];
	}

	cout << res % mod;

	return 0;
}