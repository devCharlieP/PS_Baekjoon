#include <iostream>
using namespace std;

int main()
{
	int A, B, C;
	int mul;
	int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	cin >> A >> B >> C;

	mul = A * B * C;

	for (int i = 0; i < 10; i++)
	{
		if (mul >= 1)
		{
			array[mul % 10]++;
			mul /= 10;
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		
		cout << array[i] << endl;
		
	}

	return 0;
}