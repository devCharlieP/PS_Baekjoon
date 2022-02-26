#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector < vector <int> > v;
	vector <int> xy(2);

	for (int i = 0; i < n; i++)
	{
		cin >> xy[0] >> xy[1];
		v.push_back(xy);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << v[i][0] << " " << v[i][1] << "\n";
	}

	return 0;
}