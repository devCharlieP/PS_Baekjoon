#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double n;
	cin >> n;

	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	vector<double> vec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	int p = round(n / 100 * 15);

	double sum = 0;

	sort(vec.begin(), vec.end());

	for (int i = p; i < n - p; i++)
	{
		sum += vec[i];
	}

	cout << round(sum / (n - (2 * p)));	

	return 0;
}