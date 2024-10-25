#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int N, M;
vector<vector<int>> map;
vector<pair<int, int>> pos_virus;

vector<int> di = { -1, 1, 0, 0 };
vector<int> dj = { 0, 0, -1, 1 };

int res = 0;

void virus()
{
	for (int i = 0; i < pos_virus.size(); i++)
	{
		queue<pair<int, int>> q;

		q.push(pair<int, int>(pos_virus[i].first, pos_virus[i].second));

		while (!q.empty())
		{
			pair<int, int> front = q.front();

			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int des_i = front.first + di[j];
				int des_j = front.second + dj[j];

				if (0 <= des_i && des_i < N && 0 <= des_j && des_j < M && map[des_i][des_j] == 0)
				{
					map[des_i][des_j] = 2;
					q.push(pair<int, int>(des_i, des_j));
				}
			}
		}
	}

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

	res = max(res, cnt);
}

void dfs(int depth)
{
	if (depth == 3)
	{
		vector<vector<int>> map_temp;
		map_temp = map;

		virus();

		map = map_temp;

		return;
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				dfs(depth + 1);
				map[i][j] = 0;
			}
		}
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

			if (map[i][j] == 2)
			{
				pos_virus.push_back(pair<int, int>(i, j));
			}
		}
	}

	dfs(0);

	cout << res;

	return 0;
}