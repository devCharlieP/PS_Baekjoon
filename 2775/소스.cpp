#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;

	cin >> t;

	vector <int> k(t), n(t), result(t);	
	vector < vector <int> > v;
	v.assign(15, vector<int>(15, 0));

	for (int i = 0; i <= 14; i++)
	{
		v.at(0).at(i) = i;
	}
	
	for (int i = 0; i < t; i++)
	{
		cin >> k.at(i) >> n.at(i);

		for (int j = 1; j <= k.at(i); j++)
		{
			for (int q = 1; q <= n.at(i); q++)
			{
				v.at(j).at(q) += v.at(j - 1).at(q) + v.at(j).at(q - 1);
			}
		}

		result.at(i) = v.at(k.at(i)).at(n.at(i));

		for (int j = 1; j <= k.at(i); j++)
		{
			for (int q = 0; q <= n.at(i); q++)
			{
				v.at(j).at(q) = 0;
			}
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result.at(i) << endl;
	}

	return 0;
}