#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

long long mod = 1000000007;

long long dc(long long B, long long x)
{
	if (x == 1)
	{
		return B % mod;
	}

	long long temp = 0;
	temp = dc(B, x / 2);

	temp = temp * temp % mod;

	if (x % 2 == 0)
	{
		return temp;
	}
	else
	{
		return (temp * B) % mod;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long N, K;
	cin >> N >> K;

	long long A = 1;
	for (int i = N - (K - 1); i <= N; i++)
	{
		A = (A * i) % mod;
	}

	long long B = 1;
	for (int i = 1; i <= K; i++)
	{
		B = (B * i) % mod;
	}

	B = dc(B, mod - 2);

	cout << A * B % mod;

	return 0;
}