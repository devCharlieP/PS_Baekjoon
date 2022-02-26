#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

vector <int> vec(11);

int fac(int n)
{
	if (vec[n] != 0)
	{
		return vec[n];
	}

	if (n == 1)
	{
		return 1;
	}

	return vec[n] = n * fac(n - 1);
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vec[0] = 1;

	int N, K;
	cin >> N >> K;
	
	cout << fac(N) / (fac(K) * fac(N - K));

	return 0;
}