#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <vector<int>> vec(2001, vector <int>(2001));
vector <int> ch(2001);
int n;
int res = 0;

void dfs(int L, int cnt)
{
	if (cnt == 5)
	{
		res = 1;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (ch[i] == 0 && vec[L][i] == 1)
		{
			ch[i] = 1;
			dfs(i, cnt + 1);
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		vec[x][y] = 1;
		vec[y][x] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		if (res == 1)
		{
			break;
		}

		ch[i] = 1;
		dfs(i, 1);
		ch[i] = 0;
	}

	cout << res;

	return 0;
}