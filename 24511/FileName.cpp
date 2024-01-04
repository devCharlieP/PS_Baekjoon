#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector <int> A(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	vector <int> B(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> B[i];
	}

	int M;
	cin >> M;

	vector <int> C(M + 1);
	for (int i = 1; i <= M; i++)
	{
		cin >> C[i];
	}

	int cnt = M;

	for (int i = N; i >= 1; i--)
	{
		if (A[i] == 0)
		{
			cout << B[i] << " ";
			cnt--;
		}

		if (cnt == 0)
		{
			exit(0);
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cout << C[i] << " ";
		cnt--;

		if (cnt == 0)
		{
			break;
		}
	}

	return 0;
}