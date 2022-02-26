#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	vector<int> vec;

	for (int i = 0; i < n; i++)
	{
		vec.push_back(i + 1);
	}

	vector <int> idx(m);

	for (int i = 0; i < n - m; i++)
	{
		idx.push_back(1);
	}

	do
	{
		for (int i = 0; i < idx.size(); i++)
		{
			if (idx[i] == 0)
			{
				cout << vec[i] << " ";
			}
		}
		cout << endl;

	} while (next_permutation(idx.begin(), idx.end()));

	return 0;
}