#include <iostream>
using namespace std;

int main()
{

	int E, S, M;

	cin >> E >> S >> M;

	int i = 0, j = 0, k = 0;
	int result = 0;
	bool x = false, y = false, z = false;

	while (1)
	{
		i++;
		
		if (i > 15)
		{
			i = 1;
		}
		if (i == E)
		{
			x = true;
		}

		j++;
		
		if (j > 28)
		{
			j = 1;
		}
		if (j == S)
		{
			y = true;
		}

		k++;
		
		if (k > 19)
		{
			k = 1;
		}
		if (k == M)
		{
			z = true;
		}

		result++;

		if (x == true && y == true && z == true)
		{
			break;
		}
		else
		{
			x = false;
			y = false;
			z = false;
		}
	}

	cout << result << endl;

	return 0;
}