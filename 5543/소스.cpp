#include <iostream>
#include <limits>
using namespace std;

int main()
{

	int Burger[3];
	int Beverage[2];
	int save1 = numeric_limits<int>::max();
	int save2;

	for (int i = 0; i < 3; i++)
		cin >> Burger[i];

	for (int i = 0; i < 2; i++)
		cin >> Beverage[i];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			save2 = Burger[i] + Beverage[j] - 50;

			if (save2 < save1)
			{
				save1 = save2;
			}
		}
	}

	cout << save1 << endl;

	return 0;

}