#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector <int> vec;
	vector <int> res;

	for (int i = 0; i < 9; i++)
	{
		int n = 0;
		cin >> n;

		vec.push_back(n);
	}

	bool check = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			int sum = 0;

			for (int k = 0; k < 9; k++)
			{
				if (k != i && k != j)
					sum += vec[k];
			}

			if (sum == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
						res.push_back(vec[k]);
				}

				check = true;
				break;
			}
		}

		if (check == true)
			break;
	}

	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

	return 0;
}