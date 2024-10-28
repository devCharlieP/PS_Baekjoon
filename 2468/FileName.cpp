#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> ch;

vector<int> di = { -1, 1, 0, 0 };
vector<int> dj = { 0, 0, -1, 1 };

void dfs(int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		int dest_i = i + di[k];
		int dest_j = j + dj[k];

		if (0 <= dest_i && dest_i < N && 0 <= dest_j && dest_j < N && ch[dest_i][dest_j])
		{
			ch[dest_i][dest_j] = false;
			dfs(dest_i, dest_j);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	map = vector<vector<int>>(N, vector<int>(N));
	ch = vector<vector<bool>>(N, vector<bool>(N, true));

	int maxi = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			maxi = max(maxi, map[i][j]);
		}
	}

	int res = 1;

	for (int i = 1; i <= maxi; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (map[j][k] <= i)
				{
					ch[j][k] = false;
				}
			}
		}

		int cnt = 0;

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (ch[j][k])
				{
					ch[j][k] = false;
					cnt++;
					dfs(j, k);
				}
			}
		}

		res = max(res, cnt);

		ch = vector<vector<bool>>(N, vector<bool>(N, true));
	}

	cout << res;

	return 0;
}