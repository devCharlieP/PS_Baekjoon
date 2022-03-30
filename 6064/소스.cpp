#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int gcd(int M, int N)
{
	if (N == 0)
	{
		return M;
	}
	else
	{
		return gcd(N, M % N);
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	
	for (int i = 1; i <= T; i++)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		if (M < N)
		{
			swap(M, N);
			swap(x, y);
		}

		bool b = false;
		int lcm = 0;

		lcm = M * N / (gcd(M, N));

		if (M == x)
		{
			x = 0;
		}
		if (N == y)
		{
			y = 0;
		}

		for (int i = 0; i + y <= lcm; i += N)
		{
			if (i + y != 0)
			{
				if ((i + y) % M == x)
				{
					cout << i + y << endl;
					b = true;
				}
			}
		}

		if (b == false)
		{
			cout << -1 << endl;
		}
	}

	return 0;
}