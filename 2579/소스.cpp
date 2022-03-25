#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector <int> vec(305);

	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	vector <int> dp(305);

	dp[1] = vec[1];
	dp[2] = vec[1] + vec[2];
	dp[3] = max(vec[1] + vec[3], vec[2] + vec[3]);
	
	int level = 0;
	
	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + vec[i], dp[i - 3] + vec[i - 1] + vec[i]);
	}

	cout << dp[n];

	return 0;
}