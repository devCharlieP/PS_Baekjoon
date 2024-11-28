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

	int N, L, R;
	cin >> N >> L >> R;

	vector<vector<int>> A(N, vector<int>(N));
	vector<vector<int>> ch(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	vector<int> di = { -1, 1, 0, 0 };
	vector<int> dj = { 0, 0, -1, 1 };

	queue<pair<int, int>> q;

	int res = 0;

	while (1)
	{
		bool b = false;
		int cnt = 1;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (ch[i][j] == 0)
				{
					int uni_cnt = 0;
					int uni_sum = 0;

					ch[i][j] = cnt;
					q.push({ i, j });

					while (!q.empty())
					{
						int cur_i = q.front().first;
						int cur_j = q.front().second;

						uni_cnt++;
						uni_sum += A[cur_i][cur_j];

						q.pop();

						for (int i = 0; i < 4; i++)
						{
							int dest_i = cur_i + di[i];
							int dest_j = cur_j + dj[i];

							if (dest_i < 0 || dest_i >= N || dest_j < 0 || dest_j >= N || ch[dest_i][dest_j] != 0)
								continue;

							int dis = abs(A[cur_i][cur_j] - A[dest_i][dest_j]);

							if (dis < L || dis > R)
								continue;

							ch[dest_i][dest_j] = cnt;
							q.push({ dest_i, dest_j });
						}
					}

					if (uni_cnt != 1)
					{
						b = true;
						int uni_per = uni_sum / uni_cnt;

						for (int k = 0; k < N; k++)
						{
							for (int l = 0; l < N; l++)
							{
								if (ch[k][l] == cnt)
								{
									A[k][l] = uni_per;
								}
							}
						}
					}					

					cnt++;
				}
			}
		}

		ch = vector<vector<int>>(N, vector<int>(N));

		if (!b)
		{
			break;
		}
		else
		{
			res++;
		}
	}

	cout << res;

	return 0;
}