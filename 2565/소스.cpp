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

	int N;
	cin >> N;

	vector<pair<int, int>> A(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i].first >> A[i].second;
	}

	sort(A.begin(), A.end());

	vector<int> dp(N);
	dp[0] = 1;

	for (int i = 1; i < N; i++)
	{
		int maxi = 0;

		for (int j = 0; j <= i - 1; j++)
		{
			if (A[j].second < A[i].second)
			{
				maxi = max(maxi, dp[j]);
			}
		}
		dp[i] = maxi + 1;
	}

	int res = 987654321;

	for (int i = 0; i < N; i++)
	{
		res = min(res, N - dp[i]);
	}

	cout << res;

	return 0;
}