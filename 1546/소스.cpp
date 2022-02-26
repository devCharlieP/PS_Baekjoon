#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int num;
	int max = numeric_limits<int>::min();
	double sum = 0;
	double avg;

	cin >> num;

	int* arr = new int[num];

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];

		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	for (int i = 0; i < num; i++)
	{
		sum += (double)(arr[i]) / max * 100;
	}

	avg = sum / num;

	cout << avg << endl;

	delete arr;

	return 0;

}