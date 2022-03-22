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

	int T;
	cin >> T;

	vector <int> cnt_0(41);
	vector <int> cnt_1(41);

	cnt_0[0] = 1, cnt_0[1] = 0;
	cnt_1[0] = 0, cnt_1[1] = 1;

	for (int i = 1; i <= T; i++)
	{
		int N;
		cin >> N;

		for (int i = 2; i <= N; i++)
		{
			cnt_0[i] = cnt_0[i - 1] + cnt_0[i - 2];
			cnt_1[i] = cnt_1[i - 1] + cnt_1[i - 2];
		}

		cout << cnt_0[N] << " " << cnt_1[N] << endl;
	}

	return 0;
}