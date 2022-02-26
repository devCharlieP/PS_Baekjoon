#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	int x, y, w, h;
	int min = 1001;

	cin >> x >> y >> w >> h;

	vector <int> arr;

	arr.push_back(x);
	arr.push_back(y);
	arr.push_back(w - x);
	arr.push_back(h - y);

	for (int i = 0; i < arr.size(); i++)
	{
		if(arr.at(i) < min)
		{
			min = arr.at(i);
		}
	}

	cout << min;

	return 0;
}