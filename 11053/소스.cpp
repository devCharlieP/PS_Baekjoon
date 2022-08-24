#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N;
vector <int> vec(1002);
vector <int> dp(1002, 1);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> vec[i];
	}

	for (int i = N - 1; i >= 1; i--)
	{
		int max = 0;
		
		for (int j = i + 1; j <= N; j++)
		{
			if (vec[i] < vec[j])
			{
				if (max < dp[j])
				{
					max = dp[j];
				}
			}
		}

		dp[i] = max + 1;
	}


	int res = -987654321;

	for (int i = 1; i <= N; i++)
	{
		if (res < dp[i])
		{
			res = dp[i];
		}
	}

	cout << res;

	return 0;
}