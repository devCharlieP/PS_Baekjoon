#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int bridge(int N, int M)
{
	int cnt = 0;

	vector<vector<int>> C(30, vector<int>(30, 0));
	
	C[1][0] = 1;
	C[1][1] = 1;

	for (int i = 2; i <= M; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				C[i][j] = 1;
			}
			else
			{
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
	}

	return C[M][N];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	int N, M;

	for (int i = 1; i <= T; i++)
	{
		cin >> N >> M;

		cout << bridge(N, M) << endl;
	}

	return 0;
}