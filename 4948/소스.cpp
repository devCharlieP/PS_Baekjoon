#include <iostream>
#include <vector>
using namespace std;

void Eratos(int m, int n)
{
	int count = 0;

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

	for (int i = m + 1; i <= n; i++)
	{
		if (PrimeArray[i])
			count++;
	}

	cout << count << "\n";

	delete PrimeArray;
}
int main()
{
	vector <int> arr;

	while(1)
	{
		int n = 0;
		cin >> n;
		if (n != 0)
		{
			arr.push_back(n);
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		Eratos(arr.at(i), 2 * arr.at(i));
	}
		
	return 0;
}