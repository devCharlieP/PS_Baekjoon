#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define endl "\n"
using namespace std;

int N, M;
vector<vector<char>> map;

vector<int> di = { -1, 1, 0, 0 };
vector<int> dj = { 0, 0, -1, 1 };

int res = -1;

int bfs(int fn_i, int fn_j)
{
	int cnt = -1;

	vector<vector<int>> ch(N, vector<int>(M, -1));
	ch[fn_i][fn_j] = 0;

	queue<pair<int, int>> q;
	q.push({ fn_i, fn_j });

	while (!q.empty())
	{
		int cur_i = q.front().first;
		int cur_j = q.front().second;

		q.pop();

		cnt = max(cnt, ch[cur_i][cur_j]);

		for (int i = 0; i < 4; i++)
		{
			int dest_i = cur_i + di[i];
			int dest_j = cur_j + dj[i];

			if (0 <= dest_i && dest_i < N && 0 <= dest_j && dest_j < M &&
				map[dest_i][dest_j] == 'L' && ch[dest_i][dest_j] == -1)
			{
				ch[dest_i][dest_j] = ch[cur_i][cur_j] + 1;
				q.push({ dest_i, dest_j });
			}
		}
	}

	return cnt;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	map = vector<vector<char>>(N, vector<char>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'L')
			{
				res = max(res, bfs(i, j));
			}
		}
	}

	cout << res;	

	return 0;
}