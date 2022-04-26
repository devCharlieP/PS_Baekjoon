#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vec[2001];
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

	for (int i = 0; i < vec[L].size(); i++)
	{
		if (ch[vec[L][i]] == 0)
		{
			ch[vec[L][i]] = 1;
			dfs(vec[L][i], cnt + 1);
			ch[vec[L][i]] = 0;
		}

		if (res == 1)
		{
			return;
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
		vec[x].push_back(y);
		vec[y].push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		ch[i] = 1;
		dfs(i, 1);
		ch[i] = 0;

		if (res == 1)
		{
			break;
		}
	}

	cout << res;

	return 0;
}