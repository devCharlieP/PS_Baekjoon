#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int N;
int res = -1;

vector<vector<int>> move_up(vector<vector<int>> map)
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 1; i < N; i++)
		{
			if (map[i][j] != 0)
			{
				int value = map[i][j];
				int k = i;

				while (k > 0 && map[k - 1][j] == 0)
				{
					map[k - 1][j] = value;
					map[k][j] = 0;
					k--;
				}
			}
		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == map[i + 1][j])
			{
				map[i][j] = map[i][j] * 2;
				map[i + 1][j] = 0;
			}
		}
	}

	for (int j = 0; j < N; j++)
	{
		for (int i = 1; i < N; i++)
		{
			if (map[i][j] != 0)
			{
				int value = map[i][j];
				int k = i;

				while (k > 0 && map[k - 1][j] == 0)
				{
					map[k - 1][j] = value;
					map[k][j] = 0;
					k--;
				}
			}
		}
	}

	return map;
}

vector<vector<int>> move_down(vector<vector<int>> map)
{
	for (int j = 0; j < N; j++)
	{
		for (int i = N - 2; i >= 0; i--)
		{
			if (map[i][j] != 0)
			{
				int value = map[i][j];
				int k = i;

				while (k < N - 1 && map[k + 1][j] == 0)
				{
					map[k + 1][j] = value;
					map[k][j] = 0;
					k++;
				}
			}
		}
	}

	for (int i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == map[i - 1][j])
			{
				map[i][j] = map[i][j] * 2;
				map[i - 1][j] = 0;
			}
		}
	}

	for (int j = 0; j < N; j++)
	{
		for (int i = N - 2; i >= 0; i--)
		{
			if (map[i][j] != 0)
			{
				int value = map[i][j];
				int k = i;

				while (k < N - 1 && map[k + 1][j] == 0)
				{
					map[k + 1][j] = value;
					map[k][j] = 0;
					k++;
				}
			}
		}
	}

	return map;
}

vector<vector<int>> move_left(vector<vector<int>> map)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (map[i][j] != 0)
			{
				int value = map[i][j];
				int k = j;

				while (k > 0 && map[i][k - 1] == 0)
				{
					map[i][k - 1] = value;
					map[i][k] = 0;
					k--;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (map[i][j] == map[i][j + 1])
			{
				map[i][j] = map[i][j] * 2;
				map[i][j + 1] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (map[i][j] != 0)
			{
				int value = map[i][j];
				int k = j;

				while (k > 0 && map[i][k - 1] == 0)
				{
					map[i][k - 1] = value;
					map[i][k] = 0;
					k--;
				}
			}
		}
	}

	return map;
}

vector<vector<int>> move_right(vector<vector<int>> map)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 2; j >= 0; j--)
		{
			if (map[i][j] != 0)
			{
				int value = map[i][j];
				int k = j;

				while (k < N - 1 && map[i][k + 1] == 0)
				{
					map[i][k + 1] = value;
					map[i][k] = 0;
					k++;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			if (map[i][j] == map[i][j - 1])
			{
				map[i][j] = map[i][j] * 2;
				map[i][j - 1] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = N - 2; j >= 0; j--)
		{
			if (map[i][j] != 0)
			{
				int value = map[i][j];
				int k = j;

				while (k < N - 1 && map[i][k + 1] == 0)
				{
					map[i][k + 1] = value;
					map[i][k] = 0;
					k++;
				}
			}
		}
	}

	return map;
}

void dfs(int cnt, vector<vector<int>> map)
{
	if (cnt == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				res = max(res, map[i][j]);
			}
		}

		return;
	}

	dfs(cnt + 1, move_up(map));
	dfs(cnt + 1, move_down(map));
	dfs(cnt + 1, move_left(map));
	dfs(cnt + 1, move_right(map));
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	vector<vector<int>> map(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	dfs(0, map);

	cout << res;

	return 0;
}