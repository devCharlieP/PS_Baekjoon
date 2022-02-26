#include <iostream>
using namespace std;

int min(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int main()
{
	int c[2] = { 3, 5 };
	int M;
	cin >> M;

	int* dp = new int[M + 1];
	dp[0] = 0;

	for (int i = 1; i <= M; i++)
	{
		dp[i] = 9999999;
	}
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = c[i]; j <= M; j++)
		{
			dp[j] = min(dp[j], dp[j - c[i]] + 1);
		}
	}

	if (dp[M] == 9999999)
	{
		cout << -1;
	}
	else
	{
		cout << dp[M] << endl;
	}
	
	return 0;
}