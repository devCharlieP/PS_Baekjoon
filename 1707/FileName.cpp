#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int V, E;
vector<vector<int>> map;
vector<int> ch;

void dfs(int cur_node)
{
	for (int i = 0; i < map[cur_node].size(); i++)
	{
		int dest_node = map[cur_node][i];

		if (ch[dest_node] == 0)
		{
			if (ch[cur_node] == 1)
			{
				ch[dest_node] = 2;
			}
			else
			{
				ch[dest_node] = 1;
			}

			dfs(dest_node);
		}		
	}
}

bool check()
{
	for (int i = 1; i <= V; i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			int dest_node = map[i][j];

			if (ch[i] == ch[dest_node])
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;

		map = vector<vector<int>>(V + 1);
		ch = vector<int>(V + 1);

		for (int j = 0; j < E; j++)
		{
			int a, b;
			cin >> a >> b;

			map[a].push_back(b);
			map[b].push_back(a);
		}

		for (int i = 1; i <= V; i++)
		{
			if (ch[i] == 0)
			{
				ch[i] = 1;
				dfs(i);
			}
		}

		bool b = check();

		if (b)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}