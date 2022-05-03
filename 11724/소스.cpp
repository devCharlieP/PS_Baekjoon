#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int N, M;
int cnt = 1;
vector<int> graph[1001];
vector <int> ch(1001);

void dfs(int L)
{
	for (int i = 0; i < graph[L].size(); i++)
	{
		if (ch[graph[L][i]] == 0)
		{
			ch[graph[L][i]] = cnt;
			dfs(graph[L][i]);
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	int u, v;
	for (int i = 1; i <= M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		if (graph[i].size() == 0)
		{
			ch[i] = cnt++;
		}
		else
		{
			if (ch[i] == 0)
			{
				for (int j = 0; j < graph[i].size(); j++)
				{
					if (ch[graph[i][j]] == 0)
					{
						ch[i] = cnt;
						ch[graph[i][j]] = cnt;
						dfs(graph[i][j]);
					}
				}

				cnt++;
			}			
		}
	}

	cout << cnt - 1;

	return 0;
}