#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void star(int n, int i, int j)
{
	if (i >= (n / 3) + 1 && i <= 2 * (n / 3) &&
		j >= (n / 3) + 1 && j <= 2 * (n / 3))
	{
		cout << " ";
		return;
	}

	cout << "*";
	return;
}

void base(int n, int i, int j)
{
	if (i != 0 || j != 0)
	{
		if (i >= (n / 3) + 1 && i <= 2 * (n / 3) &&
			j >= (n / 3) + 1 && j <= 2 * (n / 3))
		{
			cout << " ";
			return;
		}
		else
		{
			cout << "*";
			return;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i >= (n / 3) + 1 && i <= 2 * (n / 3) &&
				j >= (n / 3) + 1 && j <= 2 * (n / 3))
			{
				base(n, i, j);
			}
			else
			{
				base(n / 3, i, j);
			}
		}
	}

	
}



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	base(n, 0, 0);

	return 0;
}