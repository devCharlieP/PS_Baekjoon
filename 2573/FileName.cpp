#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> map2;
vector<vector<int>> ch;

vector<int> di = { -1, 1, 0, 0 };
vector<int> dj = { 0, 0, -1, 1 };

void dfs(int cur_i, int cur_j, int num)
{
	for (int i = 0; i < 4; i++)
	{
		int dest_i = cur_i + di[i];
		int dest_j = cur_j + dj[i];

		if (map[dest_i][dest_j] != 0 && ch[dest_i][dest_j] == 0)
		{
			ch[dest_i][dest_j] = num;
			dfs(dest_i, dest_j, num);
		}
	}
}

bool fun()
{
	map2 = map;

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (map[i][j] != 0)
			{
				int cnt = 0;

				for (int k = 0; k < 4; k++)
				{
					if (map[i + di[k]][j + dj[k]] == 0)
					{
						cnt++;
					}
				}

				map2[i][j] = map2[i][j] - cnt;

				if (map2[i][j] < 0)
				{
					map2[i][j] = 0;
				}
			}
		}
	}

	map = map2;
	ch = vector<vector<int>>(N, vector<int>(M));

	bool b = true;
	int num = 1;

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (map[i][j] != 0 && ch[i][j] == 0)
			{
				ch[i][j] = num;
				dfs(i, j, num);
				num++;
				b = false;
			}
		}
	}

	return b;
}

bool check()
{
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (ch[i][j] > 1)
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	map = vector<vector<int>>(N, vector<int>(M));
	map2 = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	int res = 1;

	while (1)
	{
		if (fun())
		{
			res = 0;
			break;
		}

		if (check())
		{
			break;
		}

		res++;
	}

	cout << res;

	return 0;
}