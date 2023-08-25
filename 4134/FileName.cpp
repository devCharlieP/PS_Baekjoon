#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

void func()
{
	long long n;
	cin >> n;

	if (n == 0 || n == 1)
	{
		cout << 2 << endl;
		return;
	}

	while (1)
	{
		bool b = true;

		for (long long i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				b = false;
				break;
			}
		}

		if (b == true)
		{
			cout << n << endl;
			break;
		}

		n++;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		func();
	}

	return 0;
}