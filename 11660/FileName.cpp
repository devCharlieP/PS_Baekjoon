#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	vector<vector<int>> map(N + 1, vector<int>(N + 1));
	vector<vector<int>> sum(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	int num = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			num += map[i][j];
			sum[i][j] = num;
		}
	}

	int x1, y1, x2, y2;
	int res;

	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		res = 0;

		for (int j = 0; j <= x2 - x1; j++)
		{
			if (y1 == 1)
			{
				res += (sum[x1 + j][y2] - sum[x1 + j - 1][N]);
			}
			else
			{
				res += (sum[x1 + j][y2] - sum[x1 + j][y1 - 1]);
			}
		}

		cout << res << endl;
	}

	return 0;
}