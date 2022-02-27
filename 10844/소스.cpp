#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int mod = 1000000000;

int dp(int N)
{
	vector <vector <long long>> dp(101, vector <long long>(10));

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	if (N == 1)
	{
		return 9;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][j] = (dp[i - 1][j + 1]) % mod;
			}
			else if (j == 9)
			{
				dp[i][j] = (dp[i - 1][j - 1]) % mod;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % mod;
			}
		}
	}

	long long sum = 0;

	for (int i = 0; i <= 9; i++)
	{
		sum += dp[N][i];
	}

	return sum % mod;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	cout << dp(N);

	return 0;
}