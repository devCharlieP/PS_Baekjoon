#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int N;
int del_node;
int cnt = 0;
vector<vector<int>> tree;

void dfs(int node)
{
	if (node == del_node)
	{
		return;
	}

	if (tree[node].size() == 0)
	{
		cnt++;
		return;
	}
	else if (tree[node].size() == 1 && tree[node][0] == del_node)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < tree[node].size(); i++)
	{
		dfs(tree[node][i]);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	tree = vector<vector<int>>(N);

	int root_node = 0;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		if (a == -1)
		{
			root_node = i;
		}
		else
		{
			tree[a].push_back(i);
		}
	}

	cin >> del_node;

	dfs(root_node);

	cout << cnt;

	return 0;
}