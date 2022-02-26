#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
	int n, m;
	int min = numeric_limits<int>::max();
	cin >> n >> m;
	vector <int> arr;
	vector <int> sum;
	arr.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr.at(i);
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if(arr.at(i) + arr.at(j) + arr.at(k) <= m)
					sum.push_back(arr.at(i) + arr.at(j) + arr.at(k));
			}
		}
	}

	for (int i = 0; i < sum.size(); i++)
	{
		if (min > m - sum.at(i))
		{
			min = m - sum.at(i);
		}
	}
	
	cout << m - min;

	return 0;
}