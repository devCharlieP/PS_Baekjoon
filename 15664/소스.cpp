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
		int push;
		cin >> push;
		vec.push_back(push);
	}

	sort(vec.begin(), vec.end());

	vector <int> y;

	do
	{
		bool b = true;

		vector <int> x;

		for (int i = 0; i < m; i++)
		{
			x.push_back(vec[i]);
		}

		for (int i = 0; i < x.size() - 1; i++)
		{
			if (vec[i] > vec[i + 1])
			{
				b = false;
			}
		}

		if (y != x && b == true)
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