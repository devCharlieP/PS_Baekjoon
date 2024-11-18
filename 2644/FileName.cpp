#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int n;
int start, finish;
int res = -1;

vector<vector<int>> map;
vector<int> ch;

void dfs(int cur, int cnt)
{
	if (cur == finish)
	{
		res = cnt;

		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (map[cur][i] == 1 && ch[i] == 0)
		{
			ch[i] = 1;
			dfs(i, cnt + 1);
			ch[i] = 0;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	cin >> start >> finish;

	map = vector<vector<int>>(n + 1, vector<int>(n + 1));
	ch = vector<int>(n + 1);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	ch[start] = 1;
	dfs(start, 0);

	cout << res;

	return 0;
}