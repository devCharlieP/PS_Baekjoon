#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int T = 0;
	cin >> T;

	vector <int> R(T);
	vector <string> S(T);

	for (int i = 0; i < T; i++)
	{
		cin >> R.at(i) >> S.at(i);
	}

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < S.at(i).size(); j++)
		{
			for (int k = 0; k < R.at(i); k++)
			{
				cout << S.at(i).at(j);
			}
		}
		cout << endl;
	}

	return 0;
}