#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M;

	vector<vector<int>> Mat1(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Mat1[i][j];
		}
	}

	cin >> M >> K;
	vector<vector<int>> Mat2(M, vector<int>(K));

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> Mat2[i][j];
		}
	}

	vector<vector<int>> Mat3(N, vector<int>(K));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			for (int k = 0; k < M; k++)
			{
				Mat3[i][j] += Mat1[i][k] * Mat2[k][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << Mat3[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}