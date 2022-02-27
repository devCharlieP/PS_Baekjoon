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

	vector <vector <long long>> dp(100, vector <long long>(2));

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[N][0] + dp[N][1];

	return 0;
}