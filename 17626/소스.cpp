#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

vector <int> vec(50001);

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

	int sav = 0;
	
	for (int i = 1; i <= n; i++)
	{
		if (vec[i] == 0)
		{
			for (int j = 1; j <= i; j++)
			{

			}
		}

	}
		

	cout << vec[n];

	return 0;
}