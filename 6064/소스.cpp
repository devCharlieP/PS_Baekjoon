#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
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

		int res = 0;
		bool b = false;
		int lcm = 0;

		if (M >= N)
		{
			lcm = M * N / (gcd(M, N));
		}
		else
		{
			lcm = M * N / (gcd(N, M));
		}

		for (int i = 1; i <= lcm; i++)
		{
			if (i % M == x && i % N == y)
			{
				res = i;
				b = true;
				break;
			}
		}

		if (b == true)
		{
			cout << res << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}

	return 0;
}