#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vec(1001);

int dp(int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}

	if (vec[n] != 0)
	{
		return vec[n];
	}

	return vec[n] = (dp(n - 1) + dp (n - 2)) % 10007;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << dp(n);

	return 0;
}