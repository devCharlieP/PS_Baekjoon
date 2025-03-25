#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<vector<int>> map(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		map[a].push_back(b);
	}

	queue<pair<int, int>> q;
	q.push({X, 0});

	vector<int> cost(N + 1, INT_MAX);

	while (!q.empty())
	{
		int cur_node = q.front().first;
		int cur_cost = q.front().second;

		q.pop();

		if (cost[cur_node] < cur_cost)
		{
			continue;
		}

		cost[cur_node] = cur_cost;

		for (int i = 0; i < map[cur_node].size(); i++)
		{
			q.push({ map[cur_node][i], cur_cost + 1 });
		}
	}

	bool b = false;

	for (int i = 1; i <= N; i++)
	{
		if (cost[i] == K)
		{
			b = true;
			cout << i << endl;
		}
	}

	if (!b)
		cout << -1;

	return 0;
}