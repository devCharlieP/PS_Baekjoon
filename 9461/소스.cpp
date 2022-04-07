#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		int n;
		cin >> n;

		vector <long long> P(101);

		P[1] = 1;
		P[2] = 1;
		P[3] = 1;

		for (int i = 4; i <= n; i++)
		{
			P[i] = P[i - 2] + P[i - 3];
		}

		cout << P[n] << endl;
	}

	return 0;
}