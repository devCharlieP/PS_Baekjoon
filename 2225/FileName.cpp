#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int MOD = 1000000000;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> dp(N + 1, vector<int>(K + 1));

	for (int i = 1; i <= K; i++)
	{
		dp[1][i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		dp[i][1] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= K; j++)
		{
			dp[i][j] = ((dp[i - 1][j] % MOD) + (dp[i][j - 1] % MOD)) % MOD;
		}
	}

	cout << dp[N][K];

	return 0;
}