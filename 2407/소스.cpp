#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0, m = 0;
	
	cin >> n >> m;

	long long sum = 1;

	vector<int> arrn(m);
	vector<int> arrm(m);

	int nn = n;
	int mm = m;

	for (int i = 0; i < m; i++)
	{
		arrn.at(i) = nn--;
		arrm.at(i) = mm--;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arrn.at(i) % arrm.at(j) == 0)
			{
				arrn.at(i) = arrn.at(i) / arrm.at(j);
				arrm.at(j) = 101;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		cout << arrn.at(i) << " ";
		sum *= arrn.at(i);
	}

	cout << endl << sum;
	
	return 0;
}