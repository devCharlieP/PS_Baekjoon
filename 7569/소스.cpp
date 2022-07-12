#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

int M, N, H;
int tomato[101][101][101];
int ch[101][101][101];
int res = 0;

struct TD
{
	int M_x;
	int N_y;
	int H_z;
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N >> H;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				cin >> tomato[i][j][k];
			}
		}
	}

	queue <TD> Q;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (tomato[i][j][k] == 1)
				{
					Q.push({k, j, i});
				}
			}
		}
	}

	vector <TD> vec_pos;

	vec_pos.push_back({ 1, 0, 0 });
	vec_pos.push_back({ -1, 0, 0 });
	vec_pos.push_back({ 0, 1, 0 });
	vec_pos.push_back({ 0, -1, 0 });
	vec_pos.push_back({ 0, 0, 1 });
	vec_pos.push_back({ 0, 0, -1 });

	while (!Q.empty())
	{
		TD front = Q.front();
		Q.pop();

		for (int i = 0; i < 6; i++)
		{
			int x = front.M_x + vec_pos[i].M_x;
			int y = front.N_y + vec_pos[i].N_y;
			int z = front.H_z + vec_pos[i].H_z;

			if (x >= 1 && x <= M && y >= 1 && y <= N && z >= 1 && z <= H)
			{
				if (tomato[z][y][x] == 0)
				{
					tomato[z][y][x] = 1;
					Q.push({ x, y, z });

					ch[z][y][x] = ch[front.H_z][front.N_y][front.M_x] + 1;
				}
			}
		}
	}

	int max = -987654321;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (ch[i][j][k] > max)
				{
					max = ch[i][j][k];
				}
			}
		}
	}

	res = max;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (tomato[i][j][k] == 0)
				{
					res = -1;
				}
			}
		}
	}

	cout << res;

	return 0;
}