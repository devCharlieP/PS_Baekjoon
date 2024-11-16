#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int,int>>> map(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		map[a].push_back({ b, c });
	}

	int dep, arr;
	cin >> dep >> arr;

	vector<int> ch(N + 1, INT_MAX);

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

	ch[dep] = 0;
	pq.push({0, dep});

	while (!pq.empty())
	{
		int cur_cost = pq.top().first;
		int cur_node = pq.top().second;

		pq.pop();

		if (cur_cost > ch[cur_node])
		{
			continue;
		}

		for (int i = 0; i < map[cur_node].size(); i++)
		{
			int dest_node = map[cur_node][i].first;
			int dest_cost = map[cur_node][i].second;
				
			if (ch[cur_node] + dest_cost < ch[dest_node])
			{
				ch[dest_node] = ch[cur_node] + dest_cost;
				pq.push({ ch[dest_node], dest_node });
			}
		}
	}

	cout << ch[arr];

	return 0;
}