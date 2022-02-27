#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vec_x;
vector <int> vec_y;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;

		vec_x.push_back(x);
		vec_y.push_back(y);
	}

	return 0;
}