#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> map(N + 1, vector<int>(N + 1));

	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
	}

	int L;
	cin >> L;

	queue<pair<int, char>> dir;

	for (int i = 0; i < L; i++)
	{
		int a;
		char b;

		cin >> a >> b;

		dir.push({ a, b });
	}

	int cnt = 0;
	int idx = 1; // 0 : up, 1 : right, 2 : down, 3 : left 

	vector<vector<int>> ch(N + 1, vector<int>(N + 1));
	deque<pair<int, int>> dq;

	vector<int> di = { -1, 0, 1, 0 };
	vector<int> dj = { 0, 1, 0, -1 };

	dq.push_back({ 1, 1 });
	ch[1][1] = 1;

	while (1)
	{
		pair<int, int> dq_front = dq.front();

		int dest_i = dq_front.first + di[idx];
		int dest_j = dq_front.second + dj[idx];

		if (dest_i < 1 || dest_i > N || dest_j < 1 || dest_j > N || ch[dest_i][dest_j] == 1)
		{
			break;
		}

		dq.push_front({ dest_i, dest_j });
		ch[dest_i][dest_j] = 1;

		if (map[dest_i][dest_j] == 1)
		{
			map[dest_i][dest_j] = 0;
		}
		else
		{
			ch[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}

		cnt++;

		if (!dir.empty())
		{
			pair<int, char> dir_front = dir.front();

			if (cnt == dir_front.first)
			{
				dir.pop();

				if (dir_front.second == 'L')
				{
					idx--;

					if (idx < 0)
					{
						idx = 3;
					}
				}
				else
				{
					idx++;

					if (idx > 3)
					{
						idx = 0;
					}
				}
			}
		}
	}

	cout << cnt + 1;

	return 0;
}