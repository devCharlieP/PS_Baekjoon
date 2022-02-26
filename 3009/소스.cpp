#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int x4, y4;
	vector <int> arrx(3);
	vector <int> arry(3);

	for (int i = 0; i < 3; i++)
	{
		cin >> arrx.at(i) >> arry.at(i);
	}

	for (int i = 0; i < 3; i++)
	{
		int numx = 0;
		int numy = 0;

		for (int j = 0; j < 3; j++)
		{
			if (arrx.at(i) == arrx.at(j))
			{
				numx++;
			}

			if (arry.at(i) == arry.at(j))
			{
				numy++;
			}
		}

		if (numx == 1)
		{
			x4 = arrx.at(i);
		}

		if (numy == 1)
		{
			y4 = arry.at(i);
		}
	}

	cout << x4 << " " << y4 << endl;

	return 0;
}