#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

vector<int> di = { 1, 0, 1 };
vector<int> dj = { 0, 1, 1 };

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	vector<vector<int>> dp(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == 0 && j == 0)
			{
				dp[i][j] = map[i][j];
			}
			else if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + map[i][j];
			}
			else if (i == 0)
			{
				dp[i][j] = dp[i][j - 1] + map[i][j];
			}
			else
			{
				dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + map[i][j];
			}
		}
	}
	
	cout << dp[N - 1][M - 1];

	return 0;
}