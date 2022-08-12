#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

int N;
int res = 0;

vector <vector <int>> map(30, vector <int>(30));
vector <vector <int>> timemap(30, vector <int>(30, -1));
vector <int> dy = { -1, 0, 0, 1 };
vector <int> dx = { 0, -1, 1, 0 };

struct dxy
{
	int y;
	int x;
};

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

	queue <dxy> Q;
	queue <dxy> clear;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 9)
			{
				Q.push(dxy{i, j});
				
				map[i][j] = 0;
				timemap[i][j] = 0;
			}
		}
	}

	int size = 2;
	int cnt = 0;

	int compare = 0;
	bool b = false;

	int temp_x = 0;
	int temp_y = 0;

	while (!Q.empty())
	{
		dxy front = Q.front();
		Q.pop();

		if (map[front.y][front.x] < size && map[front.y][front.x] != 0)
		{
			if (b == false)
			{
				compare = timemap[front.y][front.x];
				b = true;

				temp_y = front.y;
				temp_x = front.x;

			}
			else if(compare == timemap[front.y][front.x])
			{
				if (front.y < temp_y)
				{
					temp_y = front.y;
					temp_x = front.x;
				}
				else if (front.y == temp_y && front.x < temp_x)
				{
					temp_y = front.y;
					temp_x = front.x;
				}
			}
		}

		if (Q.empty() && b == true)
		{
			res += timemap[temp_y][temp_x];
			timemap = vector <vector <int>>(21, vector<int>(21, -1));

			cnt++;
			if (cnt == size)
			{
				cnt = 0;
				size++;
			}

			map[temp_y][temp_x] = 0;
			timemap[temp_y][temp_x] = 0;

			Q = clear;
			b = false;

			Q.push(dxy{ temp_y, temp_x });
			front = Q.front();
		}

		for (int i = 0; i < 4; i++)
		{
			int temp_dy = front.y + dy[i];
			int temp_dx = front.x + dx[i];

			if (map[temp_dy][temp_dx] <= size && (temp_dy >= 1 && temp_dy <= N) && 
				(temp_dx >= 1 && temp_dx <= N) && timemap[temp_dy][temp_dx] == -1)
			{
				Q.push(dxy{ temp_dy, temp_dx });
				timemap[temp_dy][temp_dx] = timemap[front.y][front.x] + 1;
			}
		}
	}

	cout << res;

	return 0;
}