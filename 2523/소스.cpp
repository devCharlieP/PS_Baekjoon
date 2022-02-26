#include <iostream>
using namespace std;

int main()
{
	int N;

	cin >> N;

	for (int i = 1; i <= 2*N; i++)
	{
		if (i <= N)
		{
			for (int j = 0; j < i; j++)
			{
				cout << "*";
			}
		}
		else
		{
			for (int k = 0; k < 2*N - i; k++)
			{
				cout << "*";
			}
		}
		
		cout << endl;
	}

	return 0;
}