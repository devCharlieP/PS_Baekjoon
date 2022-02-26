#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;

	cin >> t;

	vector <int> x(t), y(t), z(t);

	for (int i = 0; i < t; i++)
	{
		vector <int> k(2);
		k.push_back(0);
		k.push_back(0);

		cin >> x.at(i) >> y.at(i);
		z.at(i) = 0;

		while (1)
		{
			k.at(0)++;
			x.at(i) += k.at(0);
			z.at(i)++;

			if (x.at(i) >= y.at(i))
			{
				break;
			}

			k.at(1)++;
			y.at(i) -= k.at(1);
			z.at(i)++;			

			if (x.at(i) >= y.at(i))
			{
				break;
			}
		}
	}

	for (int i = 0; i < t; i++)
	{
		cout << z.at(i) << endl;
	}

	return 0;
}