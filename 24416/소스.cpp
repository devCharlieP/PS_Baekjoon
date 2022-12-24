#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

vector <int> f(50);
int cnt1 = 0, cnt2 = 0;

int fib(int n)
{
	if (n == 1 || n == 2)
	{
		cnt1++;
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}

int fibonacci(int n)
{
	f[1] = 1;
	f[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		cnt2++;
	}

	return f[n];
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	fib(n);
	fibonacci(n);

	cout << cnt1 << " " << cnt2;

	return 0;
}