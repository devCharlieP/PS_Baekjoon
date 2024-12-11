#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#define endl "\n"
using namespace std;

int N, E;
vector<vector<pair<int, int>>> map;

vector<int> dijk(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> ch(N + 1, INT_MAX);

	pq.push({ 0, start });
	ch[start] = 0;

	while (!pq.empty())
	{
		int cur_node = pq.top().second;
		int cur_cost = pq.top().first;

		pq.pop();

		if (cur_cost > ch[cur_node])
		{
			continue;
		}

		for (int i = 0; i < map[cur_node].size(); i++)
		{
			int dest_node = map[cur_node][i].first;
			int dest_cost = cur_cost + map[cur_node][i].second;

			if (dest_cost < ch[dest_node])
			{
				ch[dest_node] = dest_cost;
				pq.push({ dest_cost, dest_node });
			}
		}
	}

	return ch;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> E;

	map = vector<vector<pair<int, int>>>(N + 1);

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		map[a].push_back({ b, c });
		map[b].push_back({ a, c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	vector<int> ch1 = dijk(1);
	vector<int> ch2 = dijk(v1);
	vector<int> ch3 = dijk(v2);
	
	int res;

	if ((ch1[v1] == INT_MAX || ch2[v2] == INT_MAX || ch3[N] == INT_MAX) && 
		(ch1[v2] == INT_MAX || ch3[v1] == INT_MAX || ch2[N] == INT_MAX))
	{
		res = -1;
	}
	else
	{
		res = min(ch1[v1] + ch2[v2] + ch3[N], ch1[v2] + ch3[v1] + ch2[N]);
	}

	cout << res;

	return 0;
}