#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <int> weight(n);
	vector <int> height(n);
	vector <int> result;

	for (int i = 0; i < n; i++)
	{
		cin >> weight.at(i) >> height.at(i);
	}

	for (int i = 0; i < n; i++)
	{
		int num = 1;

		for (int j = 0; j < n; j++)
		{
			if (weight.at(i) < weight.at(j) && height.at(i) < height.at(j))
			{
				num++;
			}
		}
		result.push_back(num);
	}

	for (auto& ele : result)
		cout << ele << " ";

	return 0;
}