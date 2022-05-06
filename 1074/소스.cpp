#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int N, r, c;

void rec2(int L, int cnt, int r_temp, int c_temp)
{
	if (L == 1)
	{
		if (r_temp < pow(2, L - 1))
		{
			if (c_temp < pow(2, L - 1))
			{
				cout << cnt;
			}
			else
			{
				cout << cnt + 1;
			}
		}
		else
		{
			if (c_temp < pow(2, L - 1))
			{
				cout << cnt + 2;
			}
			else
			{
				cout << cnt + 3;
			}
		}
	}
	else
	{
		if (r_temp < pow(2, L - 1))
		{
			if (c_temp < pow(2, L - 1))
			{
				rec2(L - 1, cnt, r_temp, c_temp);
			}
			else
			{
				rec2(L - 1, cnt + pow(4, L - 1), r_temp, c_temp - pow(2, L - 1));
			}
		}
		else
		{
			if (c_temp < pow(2, L - 1))
			{
				rec2(L - 1, cnt + 2 * pow(4, L - 1), r_temp - pow(2, L - 1), c_temp);
			}
			else
			{
				rec2(L - 1, cnt + 3 * pow(4, L - 1), r_temp - pow(2, L - 1), c_temp - pow(2, L - 1));
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> r >> c;

	rec2(N, 0, r, c);

	return 0;
}