#include <iostream>
#include <vector>
using namespace std;

void Eratos(int n)
{
	vector <int> era;
	int res1 = 0, res2 = 0;

	if (n <= 1) return;

	bool* PrimeArray = new bool[n + 1];

	for (int i = 2; i <= n; i++)
		PrimeArray[i] = true;

	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
	}
	for (int i = 2; i <= n; i++)
	{
		if (PrimeArray[i])
		{
			era.push_back(i);
		}
	}

	for (int i = 0; i < era.size(); i++)
	{
		for (int j = i; j < era.size(); j++)
		{
			if (era.at(i) + era.at(j) == n)
			{
				res1 = era.at(i);
				res2 = era.at(j);
			}
		}
	}

	cout << res1 << " " << res2 << "\n";

	delete PrimeArray;
}

int main()
{
	int t;
	cin >> t;

	vector <int> arr(t);

	for (int i = 0; i < t; i++)
	{
		cin >> arr.at(i);
	}

	for (int i = 0; i < t; i++)
	{
		Eratos(arr.at(i));
	}

	return 0;
}