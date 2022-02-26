#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;

	vector < vector <int> > v;

	for (int i = 0; i < t; i++)
	{
		vector <int> v2(6);

		for (int j = 0; j < 6; j++)
		{
			cin >> v2.at(j);
		}
		v.push_back(v2);
	}

	for (int i = 0; i < v.size(); i++)
	{
		int x1 = v.at(i).at(0);
		int y1 = v.at(i).at(1);
		double r1 = v.at(i).at(2);

		int x2 = v.at(i).at(3);
		int y2 = v.at(i).at(4);
		double r2 = v.at(i).at(5);

		double dis = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		if (dis == 0 && r1 == r2)
		{
			cout << "-1" << endl;
		}
		else if (dis > r1 + r2)
		{
			cout << "0" << endl;
		}
		else if (dis == r1 + r2)
		{
			cout << "1" << endl;
		}
		else if (dis < r1 + r2)
		{
			if(dis == abs(r2 - r1))
			{
				cout << "1" << endl;
			}
			else if (dis < abs(r2 - r1))
			{
				cout << "0" << endl;
			}
			else if (dis > abs(r2 - r1))
			{
				cout << "2" << endl;
			}
		}
	}

	return 0;
}