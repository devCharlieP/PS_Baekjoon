#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> coin(n);

	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	vector<int> dp(100001);

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}

	cout << dp[k];

	return 0;
}