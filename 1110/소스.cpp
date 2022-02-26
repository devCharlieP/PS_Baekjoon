#include <iostream>
using namespace std;

int main()
{
	int num;
	int num_const;

	int num_front;
	int num_back;
	int num_sum;

	int count = 1;

	cin >> num;

	num_const = num;


	while (1)
	{

		if (num < 10)
		{
			num_front = 0;
			num_back = num;
		}

		num_front = num / 10;
		num_back = num % 10;

		num_sum = num_front + num_back;

		num = num_back * 10 + num_sum % 10;

		if (num == num_const)
		{
			cout << count << endl;
			break;
		}

		count++;
	}

	return 0;
}