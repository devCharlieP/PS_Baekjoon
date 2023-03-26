#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= 2 * N - 1; i++)
	{
		int tmp = 0;

		if (i <= N)
			tmp = i;
		else
			tmp = (2 * N) - i;

		for (int j = 1; j <= N + (tmp - 1); j++)
		{
			if (N - (tmp - 1) <= j && j <= N + (tmp - 1))
				cout << "*";
			else
				cout << " ";
		}

		cout << endl;
	}

	return 0;
}