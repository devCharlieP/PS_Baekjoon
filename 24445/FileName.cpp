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

	int N, M, R;
	cin >> N >> M >> R;

	vector<vector<int>> map(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(map[i].begin(), map[i].end(), greater<int>());
	}

	queue<int> q;
	vector<int> ch(N + 1);
	int cnt = 0;

	q.push(R);
	ch[R] = ++cnt;

	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		for (int i = 0; i < map[front].size(); i++)
		{
			if (ch[map[front][i]] == 0)
			{
				ch[map[front][i]] = ++cnt;
				q.push(map[front][i]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << ch[i] << endl;
	}

	return 0;
}