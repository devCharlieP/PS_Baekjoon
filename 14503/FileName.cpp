#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;

	vector<vector<int>> map(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	vector<vector<int>> ch(N, vector<int>(M));

	int res = 0;

	vector<int> di = { -1, 0, 1, 0 };
	vector<int> dj = { 0, 1, 0, -1 };

	while (1)
	{
		if (ch[r][c] == 0)
		{
			ch[r][c] = 1;
			res++;
		}

		bool b = false;
		
		for (int i = 0; i < 4; i++)
		{
			if (ch[r + di[i]][c + dj[i]] == 0 && map[r + di[i]][c + dj[i]] == 0)
			{
				b = true;
			}
		}

		if (b)
		{
			while (1)
			{
				d--;

				if (d == -1)
				{
					d = 3;
				}

				int dest_i = r + di[d];
				int dest_j = c + dj[d];

				if (0 <= dest_i && dest_i < N && 0 <= dest_j && dest_j < M &&
					ch[dest_i][dest_j] == 0 && map[dest_i][dest_j] == 0)
				{
					r = dest_i;
					c = dest_j;
					break;
				}
			}			
		}
		else
		{
			int dest_i = r + (-1 * di[d]);
			int dest_j = c + (-1 * dj[d]);

			if (dest_i < 0 || dest_i >= N || dest_j < 0 || dest_j >= M || map[dest_i][dest_j] == 1)
			{
				break;
			}
			else
			{
				r = dest_i;
				c = dest_j;
			}
		}
	}

	cout << res;
	
	return 0;
}