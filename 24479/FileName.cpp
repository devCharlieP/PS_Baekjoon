#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int cnt = 0;
vector<vector<int>> map;
vector<int> ch;

void dfs(int deep)
{
	for (int i = 0; i < map[deep].size(); i++)
	{
		if (ch[map[deep][i]] == 0)
		{
			ch[map[deep][i]] = ++cnt;
			dfs(map[deep][i]);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, R;
	cin >> N >> M >> R;

	map = vector<vector<int>>(N + 1);
	ch = vector<int>(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (int i = 1; i < N + 1; i++)
	{
		sort(map[i].begin(), map[i].end());
	}

	ch[R] = ++cnt;
	dfs(R);

	for (int i = 1; i < ch.size(); i++)
	{
		cout << ch[i] << endl;
	}

	return 0;
}