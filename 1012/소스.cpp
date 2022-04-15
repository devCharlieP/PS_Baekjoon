#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;
int M, N, K;

vector <vector <int>> vec(51, vector <int>(51));
vector <int> dx{ 0, 1, 0, -1 };
vector <int> dy{ -1, 0, 1, 0 };

void dfs(int x, int y)
{
	for (int k = 0; k < 4; k++)
	{
		if ((y + dy[k] >= 0 && y + dy[k] < N) && (x + dx[k] >= 0 && x + dx[k] < M) 
			&& vec[y + dy[k]][x + dx[k]] == 1)
		{
			vec[y + dy[k]][x + dx[k]] = 0;
			dfs(x + dx[k], y + dy[k]);
		}
	}

	return;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> M >> N >> K;
		
		for (int i = 1; i <= K; i++)
		{
			int x, y;
			cin >> x >> y;
			vec[y][x] = 1;
		}

		int cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (vec[i][j] == 1)
				{
					cnt++;
					vec[i][j] = 0;
					dfs(j, i);
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}