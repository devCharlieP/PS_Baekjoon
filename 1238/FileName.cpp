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

	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<pair<int, int>>> map(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		map[a].push_back({ b, c });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<vector<int>> ch(N + 1, vector<int>(N + 1, INT_MAX));

	for (int i = 1; i <= N; i++)
	{
		ch[i][i] = 0;
		pq.push({ 0, i });

		while (!pq.empty())
		{
			int cur_cost = pq.top().first;
			int cur_pos = pq.top().second;

			pq.pop();

			if (cur_cost > ch[i][cur_pos])
			{
				continue;
			}

			for (int j = 0; j < map[cur_pos].size(); j++)
			{
				int dest_cost = map[cur_pos][j].second;
				int dest_pos = map[cur_pos][j].first;
				
				if (cur_cost + dest_cost < ch[i][dest_pos])
				{
					ch[i][dest_pos] = cur_cost + dest_cost;
					pq.push({ cur_cost + dest_cost, dest_pos });
				}
			}
		}
	}

	int res = 0;

	for (int i = 1; i <= N; i++)
	{
		res = max(res, ch[i][X] + ch[X][i]);
	}

	cout << res;

	return 0;
}