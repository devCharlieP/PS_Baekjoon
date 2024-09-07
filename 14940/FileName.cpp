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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m));

	pair<int, int> start;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
			{
				start = make_pair(i, j);
			}
		}
	}

	queue<pair<int, int>> q;
	vector<vector<int>> ch(n, vector<int>(m, -1));
	vector<int> di = { -1, 1, 0, 0 };
	vector<int> dj = { 0, 0, -1, 1 };

	q.push(start);
	ch[start.first][start.second] = 0;

	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dii = front.first + di[i];
			int djj = front.second + dj[i];

			if (0 <= dii && dii < n && 0 <= djj && djj < m && map[dii][djj] == 1 && ch[dii][djj] == -1)
			{
				ch[dii][djj] = ch[front.first][front.second] + 1;
				q.push(make_pair(dii, djj));
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << ch[i][j] << " ";
			}
		}

		cout << endl;
	}

	return 0;
}