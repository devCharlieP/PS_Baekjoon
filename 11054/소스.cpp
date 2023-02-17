#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int N;

vector<int> dp(vector<int> AB, vector<int> dp_AB)
{
	dp_AB[0] = 1;

	for (int i = 1; i < N; i++)
	{
		int max = 0;

		for (int j = i - 1; j >= 0; j--)
		{
			if (AB[j] < AB[i])
			{
				if (max < dp_AB[j])
				{
					max = dp_AB[j];
				}
			}
		}

		dp_AB[i] = max + 1;
	}

	return dp_AB;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	vector <int> A(N);
	vector <int> B(N);

	vector <int> dp_A(N);
	vector <int> dp_B(N);

	for (int i = 0; i < N; i++)
	{
		int push;
		cin >> push;

		A[i] = push;
		B[N - 1 - i] = push;
	}

	dp_A = dp(A, dp_A);
	dp_B = dp(B, dp_B);

	int res = -1;

	for (int i = 0; i < N; i++)
	{
		res = max(res, dp_A[i] + dp_B[N - 1 - i]);
	}

	cout << res - 1;

	return 0;
}