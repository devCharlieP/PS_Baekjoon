#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	map<string, double> m;
	m.insert({ "A+", 4.5 });
	m.insert({ "A0", 4.0 });
	m.insert({ "B+", 3.5 });
	m.insert({ "B0", 3.0 });
	m.insert({ "C+", 2.5 });
	m.insert({ "C0", 2.0 });
	m.insert({ "D+", 1.5 });
	m.insert({ "D0", 1.0 });
	m.insert({ "F", 0 });

	double sum1 = 0;
	double sum2 = 0;

	for (int i = 1; i <= 20; i++)
	{
		string ob;
		double point;
		string score;

		cin >> ob >> point >> score;

		if (score != "P")
		{
			sum1 += point * m[score];
			sum2 += point;
		}
	}
	
	cout << fixed;
	cout.precision(6);
	cout << sum1 / sum2;

	return 0;
}