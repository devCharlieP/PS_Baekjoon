#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> vec(N + 1);

	for (int x = 1; x <= M; x++)
	{
		int i, j, k;
		cin >> i >> j >> k;

		for (int y = i; y <= j; y++)
		{
			vec[y] = k;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << vec[i] << " ";
	}

	return 0;
}