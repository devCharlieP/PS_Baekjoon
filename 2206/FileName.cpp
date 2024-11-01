#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#define endl "\n"
using namespace std;

struct s
{
	int first;
	int second;
	int count;
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N, vector<int>(M));
	vector<vector<vector<int>>> ch(N, vector<vector<int>>(M, vector<int>(2)));

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < M; j++)
		{	
			map[i][j] = s[j] - '0';
		}
	}

	vector<int> di = { -1, 1, 0, 0 };
	vector<int> dj = { 0, 0, -1, 1 };

	queue<s> q;
	q.push({0, 0, 0});

	ch[0][0][0] = 1;

	while (!q.empty())
	{
		s front = q.front();
			
		q.pop();

		int cur_i = front.first;
		int cur_j = front.second;
		int cur_cnt = front.count;

		if (cur_i == N - 1 && cur_j == M - 1)
		{
			cout << ch[cur_i][cur_j][cur_cnt];
			return 0;
		}		

		for (int i = 0; i < 4; i++)
		{
			int dest_i = cur_i + di[i];
			int dest_j = cur_j + dj[i];

			if (dest_i < 0 || dest_i >= N || dest_j < 0 || dest_j >= M)
			{
				continue;
			}

			if (map[dest_i][dest_j] == 0 && ch[dest_i][dest_j][cur_cnt] == 0)
			{
				ch[dest_i][dest_j][cur_cnt] = ch[cur_i][cur_j][cur_cnt] + 1;
				q.push({ dest_i, dest_j, cur_cnt });
			}
			else if (map[dest_i][dest_j] == 1 && cur_cnt == 0)
			{
				ch[dest_i][dest_j][cur_cnt + 1] = ch[cur_i][cur_j][cur_cnt] + 1;
				q.push({ dest_i, dest_j, cur_cnt + 1 });
			}
		}
	}

	cout << -1;

	return 0;
}