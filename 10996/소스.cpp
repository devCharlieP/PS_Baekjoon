#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;

	for (int i = 1; i <= n * 2; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j % 2 != 0)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		else
		{
			for (int k = 1; k <= n; k++)
			{
				if(k % 2 != 0)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}
			}
			cout << endl;
		}
	}

	return 0;
}