#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int M, N;
vector<vector<int>> vec;
vector<vector<int>> dp;

vector<int> di = { 1, -1, 0, 0 };
vector<int> dj = { 0, 0, -1, 1 };

int dfs(int cur_i, int cur_j)
{
	if (cur_i == M - 1 && cur_j == N - 1)
	{
		return 1;
	}

	if (dp[cur_i][cur_j] != -1)
	{
		return dp[cur_i][cur_j];
	}

	dp[cur_i][cur_j] = 0;

	for (int i = 0; i < 4; i++)
	{
		int dest_i = cur_i + di[i];
		int dest_j = cur_j + dj[i];

		if (0 <= dest_i && dest_i < M && 0 <= dest_j && dest_j < N &&
			vec[cur_i][cur_j] > vec[dest_i][dest_j])
		{
			dp[cur_i][cur_j] += dfs(dest_i, dest_j);
		}
	}

	return dp[cur_i][cur_j];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N;

	vec = vector<vector<int>>(M, vector<int>(N));
	dp = vector<vector<int>>(M, vector<int>(N, -1));

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> vec[i][j];
		}
	}

	cout << dfs(0, 0);

	return 0;
}