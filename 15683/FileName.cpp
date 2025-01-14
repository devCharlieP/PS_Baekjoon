#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

struct cctv
{
	int di;
	int dj;
	int num;
};

int N, M;
vector<vector<int>> map;
vector<cctv> cctvs;

int res = 987654321;

vector<int> di = { 0, -1, 1, 0, 0 };
vector<int> dj = { 0, 0, 0, -1, 1 };

void keepWatch(int cur_i, int cur_j, int dir)
{
	while (1)
	{
		int dest_i = cur_i + di[dir];
		int dest_j = cur_j + dj[dir];

		if (dest_i < 0 || dest_i >= N || dest_j < 0 || dest_j >= M || map[dest_i][dest_j] == 6)
			return;

		if (map[dest_i][dest_j] == 0)
		{
			map[dest_i][dest_j] = -1;
		}
		
		cur_i = dest_i;
		cur_j = dest_j;
	}
}

void dfs(int depth)
{
	if (depth == cctvs.size())
	{
		int cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
				{
					cnt++;
				}
			}
		}

		res = min(res, cnt);

		return;
	}

	int cur_i = cctvs[depth].di;
	int cur_j = cctvs[depth].dj;
	int cur_num = cctvs[depth].num;

	vector<vector<int>> temp_map = map;

	if (cur_num == 1)
	{
		keepWatch(cur_i, cur_j, 1);
		dfs(depth + 1);
		map = temp_map;

		keepWatch(cur_i, cur_j, 2);
		dfs(depth + 1);
		map = temp_map;

		keepWatch(cur_i, cur_j, 3);
		dfs(depth + 1);
		map = temp_map;

		keepWatch(cur_i, cur_j, 4);
		dfs(depth + 1);
		map = temp_map;
	}
	else if (cur_num == 2)
	{
		keepWatch(cur_i, cur_j, 1);
		keepWatch(cur_i, cur_j, 2);
		dfs(depth + 1);
		map = temp_map;

		keepWatch(cur_i, cur_j, 3);
		keepWatch(cur_i, cur_j, 4);
		dfs(depth + 1);
		map = temp_map;
	}
	else if (cur_num == 3)
	{
		keepWatch(cur_i, cur_j, 1);
		keepWatch(cur_i, cur_j, 4);
		dfs(depth + 1);
		map = temp_map;

		keepWatch(cur_i, cur_j, 4);
		keepWatch(cur_i, cur_j, 2);
		dfs(depth + 1);
		map = temp_map;

		keepWatch(cur_i, cur_j, 2);
		keepWatch(cur_i, cur_j, 3);
		dfs(depth + 1);
		map = temp_map;

		keepWatch(cur_i, cur_j, 3);
		keepWatch(cur_i, cur_j, 1);
		dfs(depth + 1);
		map = temp_map;
	}
	else if (cur_num == 4)
	{
		keepWatch(cur_i, cur_j, 1);
		keepWatch(cur_i, cur_j, 3);
		keepWatch(cur_i, cur_j, 4);
		dfs(depth + 1);
		map = temp_map;

		keepWatch(cur_i, cur_j, 1);
		keepWatch(cur_i, cur_j, 4);
		keepWatch(cur_i, cur_j, 2);
		dfs(depth + 1);
		map = temp_map;

		keepWatch(cur_i, cur_j, 4);
		keepWatch(cur_i, cur_j, 2);
		keepWatch(cur_i, cur_j, 3);
		dfs(depth + 1);
		map = temp_map;

		keepWatch(cur_i, cur_j, 2);
		keepWatch(cur_i, cur_j, 3);
		keepWatch(cur_i, cur_j, 1);
		dfs(depth + 1);
		map = temp_map;
	}
	else if (cur_num == 5)
	{
		keepWatch(cur_i, cur_j, 1);
		keepWatch(cur_i, cur_j, 2);
		keepWatch(cur_i, cur_j, 3);
		keepWatch(cur_i, cur_j, 4);
		dfs(depth + 1);
		map = temp_map;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	map = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (1 <= map[i][j] && map[i][j] <= 5)
			{
				cctvs.push_back({ i , j, map[i][j] });
			}
		}
	}

	dfs(0);

	cout << res;

	return 0;
}