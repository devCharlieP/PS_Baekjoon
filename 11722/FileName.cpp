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

	vector<int> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	vector<int> dp(N);
	dp[0] = 1;

	for (int i = 1; i < N; i++)
	{
		int maxi = 0;

		for (int j = 0; j < i; j++)
		{
			if (vec[i] < vec[j])
			{
				maxi = max(maxi, dp[j]);
			}
		}

		dp[i] = maxi + 1;
	}

	int res = -1;

	for (int i = 0; i < N; i++)
	{
		res = max(res, dp[i]);
	}

	cout << res;

	return 0;
}