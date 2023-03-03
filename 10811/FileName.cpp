#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> vec(N + 1);

	for (int i = 1; i <= N; i++)
	{
		vec[i] = i;
	}

	for (int t = 1; t <= M; t++)
	{
		int i, j;
		cin >> i >> j;

		for (int u = i; u <= (j - i) / 2 + i; u++)
		{
			swap(vec[u], vec[j - u + i]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << vec[i] << " ";
	}

	return 0;
}