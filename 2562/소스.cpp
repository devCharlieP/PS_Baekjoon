#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int a[9];
	int num;

	int max = numeric_limits<int>::min();

	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];

		if (max < a[i])
		{
			max = a[i];
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (a[i] == max)
		{
			num = i + 1;
		}
	}

	cout << max << endl << num << endl;

	return 0;
}