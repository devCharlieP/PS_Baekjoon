#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a % b);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	vector<int> G(N);

	for (int i = 0; i < N - 1; i++)
	{
		G.push_back(vec[i + 1] - vec[i]);
	}

	int res = GCD(G[G.size() - 1], G[G.size() - 2]);

	for (int i = G.size() - 3; i >= 0; i--)
	{
		res = GCD(res, G[i]);
	}

	cout << (vec[N - 1] - vec[0]) / res + 1 - N;

	return 0;
}