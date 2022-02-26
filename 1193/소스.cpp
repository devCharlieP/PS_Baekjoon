#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;

	int x = 1;
	int y = 1;

	for (int i = 1; i < a;)
	{
		if (x <= y)
		{
			if (x == 1 && y % 2 == 1)
			{
				i++;
				y++;
			}

			if (i == a)
			{
				break;
			}
			
			int c = y;

			for (int j = 1; j < c; j++)
			{
				i++;
				x++;
				y--;

				if (i == a)
				{
					break;
				}
			}

			if (i == a)
			{
				break;
			}
		}

		if ( x > y )
		{
			if (y == 1 && x % 2 == 0)
			{
				i++;
				x++;
			}	

			if (i == a)
			{
				break;
			}

			int c = x;

			for (int j = 1; j < c; j++)
			{
				i++;
				x--;
				y++;

				if (i == a)
				{
					break;
				}
			}

			if (i == a)
			{
				break;
			}
		}
	}

	cout << x << "/" << y;
	return 0;
}