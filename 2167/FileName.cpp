#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> vec(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> vec[i][j];
		}
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int res = 0;

		for (int x = a - 1; x < c; x++)
		{
			for (int y = b - 1; y < d; y++)
			{
				res += vec[x][y];
			}
		}

		cout << res << endl;
	}

	return 0;
}