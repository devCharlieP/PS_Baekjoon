#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int n;
vector<int> num;
vector<int> op(4);

int res_max = -1000000001;
int res_min = 1000000001;

void fun(int pt, int res)
{
	if (pt == n)
	{
		if (res < res_min)
		{
			res_min = res;
		}

		if (res > res_max)
		{
			res_max = res;
		}

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (op[i] > 0)
		{
			op[i] = op[i] - 1;

			if (i == 0)
			{
				fun(pt + 1, res + num[pt]);
			}
			else if (i == 1)
			{
				fun(pt + 1, res - num[pt]);
			}
			else if (i == 2)
			{
				fun(pt + 1, res * num[pt]);
			}
			else
			{
				fun(pt + 1, res / num[pt]);
			}

			op[i] = op[i] + 1;
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	num = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	}

	fun(1, num[0]);

	cout << res_max << endl << res_min;

	return 0;
}