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

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int,int>>> graph(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 1});

	vector<int> ch(N + 1);

	int res = 0;
	
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