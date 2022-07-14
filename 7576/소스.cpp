#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

int M, N;
int tomato[1001][1001];
int ch[1001][1001];

struct TD
{
	int M_x;
	int N_y;
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> tomato[i][j];
		}
	}

	queue <TD> Q;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (tomato[i][j] == 1)
			{
				Q.push({ j, i });
			}
		}
	}

	vector <TD> dxy;
	dxy.push_back({ 1, 0 });
	dxy.push_back({ -1, 0 });
	dxy.push_back({ 0, 1 });
	dxy.push_back({ 0, -1 });

	int res = 0;

	while (!Q.empty())
	{
		TD front = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = front.M_x + dxy[i].M_x;
			int y = front.N_y + dxy[i].N_y;

			if (x >= 1 && x <= M && y >= 1 && y <= N)
			{
				if (tomato[y][x] == 0)
				{
					tomato[y][x] = 1;
					Q.push({ x, y });
					ch[y][x] = ch[front.N_y][front.M_x] + 1;
					res = ch[y][x];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (tomato[i][j] == 0)
			{
				res = -1;
			}
		}
	}

	cout << res;

	return 0;
}