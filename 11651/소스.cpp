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
		cin >> xy[1] >> xy[0];
		v.push_back(xy);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << v[i][1] << " " << v[i][0] << "\n";
	}

	return 0;
}