#include <iostream>
#include <vector>
using namespace std;

int main()
{
	
	int n;
	cin >> n;

	vector <int> arr(n);
	int save = 0;

	for (int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> arr.at(i);

		for (int j = 1; j <= arr.at(i); j++)
		{
			if (arr.at(i) % j == 0)
			{
				num++;
			}
		}

		if (num == 2)
		{
			save++;
		}
	}

	cout << save;

	return 0;
}