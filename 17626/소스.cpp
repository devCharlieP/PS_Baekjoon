#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

vector <int> vec(50003, 4);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	{
		int i = 1;

		while (pow(i, 2) <= 50000)
		{
			vec[pow(i, 2)] = 1;
			i++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (vec[i] != 0)
		{
			for (int j = 1; j * j <= i; j++)
			{
				vec[i] = min(vec[i], vec[j * j] + vec[i - (j * j)]);
			}

		}
	}

	cout << vec[n];
	
	return 0;
}