#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector <int> num(n);

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	vector <int> dp(n);

	dp[0] = num[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + num[i], num[i]);
	}

	int res = dp[0];

	for (int i = 1; i < n; i++)
	{
		res = max(dp[i], res);
	}

	cout << res;

	return 0;
}