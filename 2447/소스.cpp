#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void star(int n, int i, int j)
{
	if ((i % n) >= (n / 3) + 1 && (i % n) <= 2 * (n / 3) &&
		(j % n) >= (n / 3) + 1 && (j % n) <= 2 * (n / 3))
	{
		cout << " ";
	}
	else
	{
		if (n == 3)
		{
			cout << "*";
		}
		else
		{
			star(n / 3, i, j);
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			star(n, i, j);
		}
		cout << endl;
	}

	return 0;
}