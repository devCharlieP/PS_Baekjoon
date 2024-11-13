#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int M, N;
int res = 0;

vector<vector<int>> map;

vector<int> di = {-1, 1, 0, 0};
vector<int> dj = {0, 0, -1, 1};

int dfs(int cur_i, int cur_j)
{
	res++;

	for (int i = 0; i < 4; i++)
	{
		int dest_i = cur_i + di[i];
		int dest_j = cur_j + dj[i];

		if (dest_i < 0 || dest_i >= M || dest_j < 0 || dest_j >= N || map[dest_i][dest_j] == 1)
		{
			continue;
		}

		map[dest_i][dest_j] = 1;
		dfs(dest_i, dest_j);
	}

	return res;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int K;

	cin >> M >> N >> K;

	map = vector<vector<int>>(M, vector<int>(N));

	for (int t = 0; t < K; t++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				map[i][j] = 1;
			}
		}
	}

	vector<int> res_vec;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				res_vec.push_back(dfs(i, j));
				res = 0;
			}
		}
	}

	sort(res_vec.begin(), res_vec.end());

	cout << res_vec.size() << endl;

	for (int i = 0; i < res_vec.size(); i++)
	{
		cout << res_vec[i] << " ";
	}

	return 0;
}