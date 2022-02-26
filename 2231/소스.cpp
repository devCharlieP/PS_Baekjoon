#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		vector <int> arr;
		int sum = 0;
		int j = i;
			
		while (1)
		{
			if (j < 10)
			{
				arr.push_back(j);
				break;
			}
			arr.push_back(j % 10);
			
			j = j / 10;
		}

		for (int k = 0; k < arr.size(); k++)
		{
			sum += arr.at(k);
		}

		sum += i;

		if (sum == n)
		{
			cout << i;
			break;
		}

		if (i == n)
		{
			cout << "0";
		}
	}
	return 0;
}