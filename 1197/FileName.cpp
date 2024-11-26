#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int V, E;
	cin >> V >> E;

	vector<vector<pair<int, int>>> graph(V + 1);

	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		graph[A].push_back({ B, C });
		graph[B].push_back({ A, C });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });

	vector<int> ch(V + 1);

	long long res = 0;

	while (!pq.empty())
	{
		int cur_cost = pq.top().first;
		int cur_pos = pq.top().second;

		pq.pop();

		if (ch[cur_pos] == 1)
		{
			continue;
		}

		ch[cur_pos] = 1;

		res += cur_cost;
				
		for (int i = 0; i < graph[cur_pos].size(); i++)
		{
			pq.push({ graph[cur_pos][i].second, graph[cur_pos][i].first });
		}
	}

	cout << res;

	return 0;
}