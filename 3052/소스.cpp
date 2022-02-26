#include <iostream>
using namespace std;

int main()
{
	int array[10];
	int per[10];
	int num = 10;

	for (int i = 0; i < 10; i++)
	{
		cin >> array[i];
		per[i] = array[i] % 42;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (per[i] == per[j])
			{
				num--;
				break;
			}
		}
	}

	cout << num << endl;

	return 0;
}