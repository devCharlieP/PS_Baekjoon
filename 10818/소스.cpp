#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int n;
	int min = numeric_limits<int>::max();
	int max = numeric_limits<int>::min();

	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}
	cout << min << " " << max;

	delete arr;

	return 0;
}