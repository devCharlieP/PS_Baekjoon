#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int N, M;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<int> dist;
vector<int> ch;
int res = 999999999;

void dfs(int a, int depth)
{
	if (depth == M)
	{
		int sum = 0;

		for (int i = 0; i < dist.size(); i++)
		{
			sum += dist[i];
		}

		res = min(sum, res);

		return;
	}

	for (int i = a; i < chicken.size(); i++)
	{
		if (ch[i] == 0)
		{
			vector<int> dist2 = dist;

			for (int j = 0; j < home.size(); j++)
			{
				dist[j] = min(dist[j], abs(chicken[i].first - home[j].first) + abs(chicken[i].second - home[j].second));
			}

			ch[i] = 1;
			dfs(i, depth + 1);
			ch[i] = 0;

			dist = dist2;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int a;
			cin >> a;

			if (a == 1)
			{
				home.push_back(make_pair(i, j));
			}
			else if (a == 2)
			{
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	dist = vector<int>(home.size(), 999999999);
	ch = vector<int>(chicken.size());

	dfs(0, 0);

	cout << res;

	return 0;
}