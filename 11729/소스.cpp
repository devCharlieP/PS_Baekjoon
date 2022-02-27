#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int cnt(int n)
{
	if (n == 1)
	{
		return 1;
	}

	return 2 * cnt(n - 1) + 1;
}

void hanoi(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << " " << b << " " << endl;
		return;
	}

	hanoi(a, 6 - a - b, n - 1);

	cout << a << " " << b << endl;

	hanoi(6 - a - b, b, n - 1);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a = 1, b = 3;

	int n;
	cin >> n;

	cout << cnt(n) << endl;

	hanoi(a, b, n);

	return 0;
}