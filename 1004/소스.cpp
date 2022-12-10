#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

void solve()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		int cx, cy, r;
		cin >> cx >> cy >> r;

		int len1 = sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2));
		int len2 = sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2));

		if (len1 < r || len2 < r) 
		{
			if (!(len1 < r && len2 < r))
			{
				cnt++;
			}
		}
	}

	cout << cnt << endl;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		solve();
	}

	return 0;
}