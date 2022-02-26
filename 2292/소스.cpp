#include <iostream>
using namespace std;

int main()
{
	long n;

	long  a = 1, i = 1;
	long  j = 0;
	int num = 1;

	cin >> n;

	if (n == 1)
	{
		cout << 1;

		return 0;
	}

	while(1)
	{
		if (n <= a)
		{
			break;
		}
				
		j = (i * i) - j;

		a = (j * 6) + 1;

		i++;

		num++;
	}

	cout << num;

	return 0;
}