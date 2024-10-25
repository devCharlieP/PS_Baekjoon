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

	int V, E;
	cin >> V >> E;

	int K;
	cin >> K;

	vector<vector<pair<int, int>>> map(V + 1);

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		map[u].push_back(pair<int, int>(v, w));
	}

	vector<int> ch(V + 1, INT_MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push(pair<int, int>(0, K));

	ch[K] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int pos = pq.top().second;

		pq.pop();

		if (dist > ch[pos])
		{
			continue;
		}

		for (int i = 0; i < map[pos].size(); i++)
		{
			int next = map[pos][i].first;
			int value = map[pos][i].second;

			if (ch[next] > ch[pos] + value)
			{
				ch[next] = ch[pos] + value;
				pq.push(pair<int, int>(ch[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (ch[i] == INT_MAX)
		{
			cout << "INF" << " ";
		}
		else
		{
			cout << ch[i] << " ";
		}
	}
	
	return 0;
}