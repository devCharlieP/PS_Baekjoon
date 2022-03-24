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

	vector <int> vec(305);

	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	vector <int> dp(305);

	dp[1] = vec[1];
	int level = 0;
	
	for (int i = 2; i <= n; i++)
	{
		if (level == 1)
		{
			level = 0;
			dp[i] = vec[i] + dp[i - 2];
		}
		else
		{
			if (vec[i] + dp[i - 1] <= vec[i] + dp[i - 2])
			{
				level = 0;
				dp[i] = vec[i] + dp[i - 2];
			}
			else
			{
				level++;
				dp[i] = vec[i] + dp[i - 1];
			}
		}
	}

	cout << dp[n];

	return 0;
}