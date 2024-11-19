#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N + 1);
	vector<int> vec(N + 1);

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		map[A].push_back(B);
		vec[B]++;
	}

	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (vec[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int front = q.front();

		cout << front << " ";

		q.pop();

		for (int i = 0; i < map[front].size(); i++)
		{
			int cur = map[front][i];

			vec[cur]--;

			if (vec[cur] == 0)
			{
				q.push(cur);
			}
		}
	}

	return 0;
}