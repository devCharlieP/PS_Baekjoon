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

	int x, y;
	cin >> x >> y;

	int K;
	cin >> K;
	
	vector<vector<int>> map(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	vector<int> dice(6);

	for (int i = 0; i < K; i++)
	{
		int ord;
		cin >> ord;

		int temp = dice[0];

		if (ord == 1)
		{
			if (y + 1 >= M)
				continue;

			y += 1;

			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[2];
			dice[2] = temp;
		}
		else if (ord == 2)
		{
			if (y - 1 < 0)
				continue;

			y -= 1;

			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = dice[1];
			dice[1] = temp;
		}
		else if (ord == 3)
		{
			if (x - 1 < 0)
				continue;

			x -= 1;

			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[4];
			dice[4] = temp;
		}
		else
		{
			if (x + 1 >= N)
				continue;

			x += 1;

			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[3];
			dice[3] = temp;
		}

		if (map[x][y] == 0)
		{
			map[x][y] = dice[0];
		}
		else
		{
			dice[0] = map[x][y];
			map[x][y] = 0;
		}		

		cout << dice[5] << endl;
	}

	return 0;
}