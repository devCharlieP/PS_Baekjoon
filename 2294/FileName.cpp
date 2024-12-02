#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> dp(100001);
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		dp[temp] = 1;
	}

	for (int i = 2; i <= k; i++)
	{
		if (dp[i] == 1)
			continue;

		int temp = INT_MAX;

		for (int j = 1; j < i; j++)
		{
			if (dp[j] == 0 || dp[i - j] == 0)
				continue;

			temp = min(temp, dp[j] + dp[i - j]);
		}

		if (temp == INT_MAX)
		{
			dp[i] = 0;
		}
		else
		{
			dp[i] = temp;
		}		
	}

	if (dp[k] != 0)
	{
		cout << dp[k];
	}
	else
	{
		cout << -1;
	}	

	return 0;
}