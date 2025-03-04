#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int N;
vector<vector<int>> map;
int cnt = 0;

void dfs(int cur_i, int cur_j, int shape)
{
	if (cur_i == N && cur_j == N)
	{
		cnt++;
		return;
	}

	if (shape == 1)
	{
		if (cur_j + 1 <= N && map[cur_i][cur_j + 1] == 0)
		{
			dfs(cur_i, cur_j + 1, 1);
		}

		if (cur_i + 1 <= N && cur_j + 1 <= N && 
			map[cur_i + 1][cur_j] == 0 && map[cur_i][cur_j + 1] == 0 && map[cur_i + 1][cur_j + 1] == 0)
		{
			dfs(cur_i + 1, cur_j + 1, 3);
		}
	}
	else if (shape == 2)
	{
		if (cur_i + 1 <= N && map[cur_i + 1][cur_j] == 0)
		{
			dfs(cur_i + 1, cur_j, 2);
		}

		if (cur_i + 1 <= N && cur_j + 1 <= N && 
			map[cur_i + 1][cur_j] == 0 && map[cur_i][cur_j + 1] == 0 && map[cur_i + 1][cur_j + 1] == 0)
		{
			dfs(cur_i + 1, cur_j + 1, 3);
		}
	}
	else
	{
		if (cur_j + 1 <= N && map[cur_i][cur_j + 1] == 0)
		{
			dfs(cur_i, cur_j + 1, 1);
		}

		if (cur_i + 1 <= N && map[cur_i + 1][cur_j] == 0)
		{
			dfs(cur_i + 1, cur_j, 2);
		}

		if (cur_i + 1 <= N && cur_j + 1 <= N &&
			map[cur_i + 1][cur_j] == 0 && map[cur_i][cur_j + 1] == 0 && map[cur_i + 1][cur_j + 1] == 0)
		{
			dfs(cur_i + 1, cur_j + 1, 3);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	map = vector<vector<int>>(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	dfs(1, 2, 1);

	cout << cnt;

	return 0;
}