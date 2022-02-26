#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	vector < vector <int> > v;
	
	while (1)
	{
		vector <int> v2(3);

		for (int j = 0; j < 3; j++)
		{
			cin >> v2.at(j);
		}
		
		if (v2.at(0) == 0)
		{
			break;
		}

		v.push_back(v2);
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.at(i).size() - 1; j++)
		{
			if (v.at(i).at(j) > v.at(i).at(j + 1))
			{
				swap(v.at(i).at(j), v.at(i).at(j + 1));
			}
		}

		if (pow(v.at(i).at(0), 2) + pow(v.at(i).at(1), 2) == pow(v.at(i).at(2), 2))
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}

	return 0;
}