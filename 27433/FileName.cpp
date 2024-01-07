#include <iostream>
#include <algorithm>

#define endl '\n'
using namespace std;

long long fac(long long N)
{
	if (N == 0 || N == 1)
	{
		return 1;
	}
	else
	{
		return N * fac(N - 1);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	cout << fac(N);

	return 0;
}