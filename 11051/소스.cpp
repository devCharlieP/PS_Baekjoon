#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> C(1001, vector<int>(1001));

	C[1][0] = 1;
	C[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				C[i][j] = 1;
			}
			else
			{
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 10007;
			}
		}
	}

	cout << C[N][K];

	return 0;
}