#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int max_x = -10001, min_x = 10001;
	int max_y = -10001, min_y = 10001;

	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;

		max_x = max(max_x, x);
		min_x = min(min_x, x);

		max_y = max(max_y, y);
		min_y = min(min_y, y);
	}

	cout << (max_x - min_x) * (max_y - min_y);

	return 0;
}