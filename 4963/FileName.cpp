#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

vector<vector<int>> map;
vector<vector<int>> ch;

vector<int> di = { -1, -1, 0, 1, 1, 1, 0, -1 };
vector<int> dj = { 0, 1, 1, 1, 0, -1, -1, -1 };

void dfs(int par_i, int par_j)
{
	for (int i = 0; i < 8; i++)
	{
		int dest_i = par_i + di[i];
		int dest_j = par_j + dj[i];

		if (0 <= dest_i && dest_i < map.size() && 0 <= dest_j && dest_j < map[0].size()
			&& map[dest_i][dest_j] == 1 && ch[dest_i][dest_j] == 0)
		{
			ch[dest_i][dest_j] = 1;
			dfs(dest_i, dest_j);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1)
	{
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
		{
			break;
		}

		map = vector<vector<int>>(h, vector<int>(w));
		ch = vector<vector<int>>(h, vector<int>(w));

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		int res = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && ch[i][j] == 0)
				{
					res++;
					ch[i][j] = 1;
					dfs(i, j);
				}
			}
		}

		cout << res << endl;
	}

	return 0;
}