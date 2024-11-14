#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int INF = 987654321;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int m;
	cin >> m;

	vector<vector<int>> map(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				map[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (c < map[a][b])
		{
			map[a][b] = c;
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == INF)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << map[i][j] << " ";
			}
		}

		cout << endl;
	}

	return 0;
}