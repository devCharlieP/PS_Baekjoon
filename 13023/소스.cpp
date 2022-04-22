#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <vector<int>> vec(2001, vector <int>(2001));
int n;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		vec[x][y] = 1;
		vec[y][x] = 1;
	}

	return 0;
}