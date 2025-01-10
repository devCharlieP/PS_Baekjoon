#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int R, C, T;
vector<vector<int>> map;

vector<int> di = { -1, 1, 0, 0 };
vector<int> dj = { 0, 0, -1, 1 };

void spread()
{
	vector<vector<int>> tempMap(R, vector<int>(C));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 0)
				continue;

			int cnt = 0;

			for (int k = 0; k < 4; k++)
			{
				if (i + di[k] < 0 || i + di[k] >= R || j + dj[k] < 0 || 
					j + dj[k] >= C || map[i + di[k]][j + dj[k]] == -1)
					continue;

				tempMap[i + di[k]][j + dj[k]] += map[i][j] / 5;
				cnt++;
			}

			map[i][j] -= (map[i][j] / 5) * cnt;
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			map[i][j] += tempMap[i][j];
		}
	}
}

void circulate(int pos, int air_i, int air_j)
{
	vector<vector<int>> tempMap;
	tempMap = map;

	tempMap[air_i][air_j] = 0;

	vector<int> cir_di;
	vector<int> cir_dj;

	if (pos == 1)
	{
		cir_di = { 0, -1, 0, 1 };
		cir_dj = { 1, 0, -1, 0 };
	}
	else
	{
		cir_di = { 0, 1, 0, -1 };
		cir_dj = { 1, 0, -1, 0 };
	}

	for (int i = 0; i < 4;)
	{
		int dest_i = air_i + cir_di[i];
		int dest_j = air_j + cir_dj[i];

		if (dest_i < 0 || dest_i >= R || dest_j < 0 || dest_j >= C)
		{
			i++;

			dest_i = air_i + cir_di[i];
			dest_j = air_j + cir_dj[i];
		}
		else if (map[dest_i][dest_j] == -1)
		{
			break;
		}

		tempMap[dest_i][dest_j] = map[air_i][air_j];
		
		air_i = dest_i;
		air_j = dest_j;
	}

	map = tempMap;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C >> T;

	map = vector<vector<int>>(R, vector<int>(C));

	int air_i = 0, air_j = 0;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == -1)
			{
				air_i = i;
				air_j = j;
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		spread();

		circulate(1, air_i - 1, air_j + 1);
		circulate(2, air_i, air_j + 1);
	}

	int res = 0;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] > 0)
			{
				res += map[i][j];
			}
		}
	}

	cout << res;

	return 0;
}