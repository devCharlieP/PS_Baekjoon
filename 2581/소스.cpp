#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m, n;
	
	cin >> m >> n;

	vector <int> arr;
	int sum = 0;

	for (int i = m; i <= n; i++)
	{
		int num = 0;

		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				num++;
			}
			if (num > 2)
			{
				break;
			}
		}

		if (num == 2)
		{
			arr.push_back(i);
		}
	}

	if (arr.size() == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		for (int i = 0; i < arr.size(); i++)
		{
			sum += arr.at(i);
		}

		cout << sum << endl << arr.at(0);
	}

	return 0;
}