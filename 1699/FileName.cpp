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

	vector<int> dp(100001);

	for (int i = 1; i <= 100000; i++)
	{
		dp[i] = i;

		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
		}
	}

	cout << dp[N];

	return 0;
}