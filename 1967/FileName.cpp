#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int n;
vector<vector<pair<int, int>>> tree;
vector<int> ch;

int val = -1;

void dfs(int cur_node, int sum)
{
	val = max(val, sum);

	for (int i = 0; i < tree[cur_node].size(); i++)
	{
		pair<int, int> dest_node = tree[cur_node][i];

		if (ch[dest_node.first] == 0)
		{
			ch[dest_node.first] = 1;
			dfs(dest_node.first, sum + dest_node.second);
			ch[dest_node.first] = 0;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	tree = vector<vector<pair<int, int>>>(n + 1);
	ch = vector<int>(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		tree[a].push_back({b, c});
		tree[b].push_back({a, c});
	}

	int res = -1;

	for (int i = 1; i <= n; i++)
	{
		ch[i] = 1;
		dfs(i, 0);
		ch[i] = 0;

		res = max(res, val);
		val = -1;
	}

	cout << res;

	return 0;
}