#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	vector <int> vec(M + 1);

	for (int i = 1; i <= M; i++)
	{
		cin >> vec[i];
	}

	int add = 0, sub = 0, pop = 0;

	for (int i = 1; i <= M; i++)
	{
		vec[i] += add - sub - pop - 1;


	}

	return 0;
}