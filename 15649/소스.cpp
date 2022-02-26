#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	vector<int> vec;

	for (int i = 0; i < n; i++)
	{
		vec.push_back(i + 1);
	}

	vector <int> y;

	do
	{
		vector <int> x;

		for (int i = 0; i < m; i++)
		{
			x.push_back(vec[i]);		
		}

		if (y != x)
		{
			for (int i = 0; i < x.size(); i++)
			{
				cout << x[i] << " ";
			}

			cout << "\n";
			y = x;
		}

	} while (next_permutation(vec.begin(), vec.end()));

	return 0;
}