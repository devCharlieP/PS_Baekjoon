#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

struct st
{
	int iR, jR;
	int iB, jB;
	int cnt;
};

bool ch[11][11][11][11];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<char>> map(N, vector<char>(M));

	int iR = 0, jR = 0;
	int iB = 0, jB = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'R')
			{
				iR = i;
				jR = j;
			}
			else if (map[i][j] == 'B')
			{
				iB = i;
				jB = j;
			}
		}
	}

	vector<int> di = { -1, 1, 0, 0 };
	vector<int> dj = { 0, 0, -1, 1 };

	queue<st> q;
	q.push({ iR, jR, iB, jB, 0 });
	ch[iR][jR][iB][jB] = true;

	while (!q.empty())
	{
		int fr_iR = q.front().iR;
		int fr_jR = q.front().jR;
		int fr_iB = q.front().iB;
		int fr_jB = q.front().jB;
		int fr_cnt = q.front().cnt;

		q.pop();

		if (fr_cnt >= 10)
		{
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int dest_iR = fr_iR;
			int dest_jR = fr_jR;
			int dest_iB = fr_iB;
			int dest_jB = fr_jB;
			int dest_cnt = fr_cnt + 1;

			int cnt_R = 0;
			while (map[dest_iR + di[i]][dest_jR + dj[i]] != '#' && map[dest_iR][dest_jR] != 'O')
			{
				dest_iR += di[i];
				dest_jR += dj[i];
				cnt_R++;
			}

			int cnt_B = 0;
			while (map[dest_iB + di[i]][dest_jB + dj[i]] != '#' && map[dest_iB][dest_jB] != 'O')
			{
				dest_iB += di[i];
				dest_jB += dj[i];
				cnt_B++;
			}

			if (map[dest_iB][dest_jB] == 'O')
			{
				continue;
			}

			if (map[dest_iR][dest_jR] == 'O')
			{
				cout << dest_cnt;
				return 0;
			}

			if (dest_iR == dest_iB && dest_jR == dest_jB)
			{
				if (cnt_R > cnt_B)
				{
					dest_iR -= di[i];
					dest_jR -= dj[i];
				}
				else
				{
					dest_iB -= di[i];
					dest_jB -= dj[i];
				}
			}

			if (!ch[dest_iR][dest_jR][dest_iB][dest_jB])
			{
				ch[dest_iR][dest_jR][dest_iB][dest_jB] = true;
				q.push({ dest_iR, dest_jR, dest_iB, dest_jB, dest_cnt });
			}
		}
	}

	cout << -1;

	return 0;
}