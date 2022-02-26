#include <iostream>
using namespace std;

int main()
{
	int num;
	int num_C;

	cin >> num;

	double* per = new double[num];

	for (int i = 0; i < num; i++)
	{
		cin >> num_C;

		int* arr = new int[num_C];
		int sum = 0;
		int avg = 0;
		int count = 0;

		for (int j = 0; j < num_C; j++)
		{
			cin >> arr[j];
			sum += arr[j];
		}

		avg = sum / num_C;

		for (int j = 0; j < num_C; j++)
		{
			if (arr[j] > avg)
			{
				count++;
			}
		}
		
		per[i] = ((double)count / (double)num_C) * 100.000;

	}

	for (int i = 0; i < num; i++)
	{
		cout << fixed;
		cout.precision(3);
		cout << per[i] << "%" << endl;
	}

	return 0;
}