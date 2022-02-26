#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;	
	cin >> t;

	vector <int> h(t), w(t), n(t);

	for (int i = 0; i < t; i++)
	{
		cin >> h.at(i) >> w.at(i) >> n.at(i);

		if (n.at(i) % h.at(i) == 0)
		{
			cout << h.at(i);

			if ((n.at(i) / h.at(i)) < 10)
			{
				cout << "0" << (n.at(i) / h.at(i)) << endl;
			}
			else
			{
				cout << (n.at(i) / h.at(i)) << endl;
			}
		}
		else
		{
			cout << n.at(i) % h.at(i);

			if ((n.at(i) / h.at(i)) + 1 < 10)
			{
				cout << "0" << (n.at(i) / h.at(i)) + 1 << endl;
			}
			else
			{
				cout << (n.at(i) / h.at(i)) + 1 << endl;
			}
		}		
	}

	return 0;
}