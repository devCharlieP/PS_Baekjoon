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

	int N;
	cin >> N;

	vector <int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	int v;
	cin >> v;

	int res = 0;

	for (int i = 0; i < N; i++)
	{
		if (v == vec[i])
		{
			res++;
		}
	}

	cout << res;

	return 0;
}