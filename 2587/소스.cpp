#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector <int> vec(5);

	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> vec[i];
		sum += vec[i];
	}

	int avg = sum / 5;

	sort(vec.begin(), vec.end());

	int cen = vec[2];

	cout << avg << endl << cen;

	return 0;
}