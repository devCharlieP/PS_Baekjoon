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

	vector<int> vec(10001);

	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	vector<int> dp(10001);

	dp[1] = vec[1];
	dp[2] = vec[1] + vec[2];
	dp[3] = max(vec[1] + vec[3], vec[2] + vec[3]);
	dp[4] = max(dp[2] + vec[4], dp[1] + vec[3] + vec[4]);

	for (int i = 5; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + vec[i], dp[i - 3] + vec[i - 1] + vec[i]);
		dp[i] = max(dp[i], dp[i - 4] + vec[i - 1] + vec[i]);
	}

	int res = -1;

	for (int i = 1; i <= n; i++)
	{
		res = max(res, dp[i]);
	}

	cout << res;

	return 0;
}