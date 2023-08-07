#include <iostream>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	int res = 1;

	for (int i = n0; i <= 101; i++)
	{
		if (a1 * i + a0 > c * i)
		{
			res = 0;
			break;
		}
	}

	cout << res;

	return 0;
}