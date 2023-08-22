#include <iostream>
#include <algorithm>
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

	int a1, a2, b1, b2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;

	int c1 = a1 * b2 + a2 * b1;
	int c2 = a2 * b2;

	int G = GCD(max(c1, c2), min(c1, c2));

	cout << c1 / G << " " << c2 / G;

	return 0;
}