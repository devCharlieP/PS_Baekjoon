#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

int N;
vector <vector <int>> map(21, vector <int>(21));
vector <vector <int>> timemap(21, vector <int>(21));
vector <vector <int>> ch(21, vector <int>(21));

struct dxy
{
	int x;
	int y;
};

vector <int> dx = { 0, 0, -1, 1 };
vector <int> dy = { -1, 1, 0, 0 };


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	dxy d1;
	queue <dxy> Q;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 9)
			{
				d1.y = i;
				d1.x = j;
				Q.push(d1);
				
				map[i][j] = 0;
				ch[i][j] = 1;
			}
		}
	}

	dxy temp;
	temp.y = 0;
	temp.x = 0;

	bool b1 = false;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 1)
			{
				temp.y = i;
				temp.x = j;
				b1 = true;

				break;
			}
		}

		if (b1 == true)
			break;
	}

	if (temp.y == 0 && temp.x == 0)
	{
		cout << 0;
		return 0;
	}

	int size = 2;
	int cnt = 0;

	while (!Q.empty())
	{
		dxy front = Q.front();
		dxy d;

		if (front.y == temp.y && front.x == temp.x)
		{
			temp.y = 0;
			temp.x = 0;

			cnt++;

			if (cnt == size)
			{
				cnt = 0;
				size++;
			}

			map[front.y][front.x] = 0;

			bool b2 = false;

			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					if (map[i][j] < size && map[i][j] != 0)
					{
						temp.y = i;
						temp.x = j;

						b2 = true;
						break;
					}
				}

				if (b2 == true)
					break;
			}

			if (temp.y == 0 && temp.x == 0)
			{
				break;
			}

			ch = vector <vector<int>>(21, vector <int>(21));
			ch[front.y][front.x] = 1;
		}

		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			d.x = front.x + dx[i];
			d.y = front.y + dy[i];

			if (map[d.y][d.x] <= size && (d.x >= 1 && d.x <= N) && (d.y >= 1 && d.y <= N) && ch[d.y][d.x] == 0)
			{
				Q.push(d);
				timemap[d.y][d.x] = timemap[front.y][front.x] + 1;
				ch[d.y][d.x] = 1;
			}
		}
	}

	int res = -987654321;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (res < timemap[i][j])
			{
				res = timemap[i][j];
			}
		}
	}

	cout << res;

	return 0;
}