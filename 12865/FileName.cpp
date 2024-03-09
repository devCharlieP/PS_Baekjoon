#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> W(101), V(101);

	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}

	vector<vector<int>>WV(101, vector<int>(100001));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (W[i] > j)
			{
				WV[i][j] = WV[i - 1][j];
			}
			else
			{
				WV[i][j] = max(WV[i - 1][j], WV[i - 1][j - W[i]] + V[i]);
			}
		}
	}

	cout << WV[N][K];

	return 0;
}