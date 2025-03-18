#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, B;
	cin >> N >> M >> B;

	int maxHeight = B;
	vector<vector<int>> map(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			maxHeight += map[i][j];
		}
	}

	maxHeight /= (N * M);

	if (maxHeight > 256)
	{
		maxHeight = 256;
	}

	vector<int> res(maxHeight + 1);

	for (int height = 0; height <= maxHeight; height++)
	{
		int timeSum = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int time = 0;

				if (map[i][j] < height)
				{
					time = height - map[i][j];
				}
				else if (map[i][j] > height)
				{
					time = 2 * (map[i][j] - height);
				}

				timeSum += time;
			}
		}

		res[height] = timeSum;
	}

	int resTime = INT_MAX;
	int resHeight = 0;

	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] <= resTime)
		{
			resTime = res[i];
			resHeight = i;
		}
	}

	cout << resTime << " " << resHeight;

	return 0;
}