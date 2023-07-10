#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;


void func()
{
	vector<int> coin = { 25, 10, 5, 1 };
	vector<int> cnt(4);

	int C;
	cin >> C;

	for (int i = 0; i < coin.size(); i++)
	{
		int coinC = coin[i];

		if (C % coinC == 0)
		{
			cnt[i] = C / coinC;
			break;
		}
		else
		{
			cnt[i] = C / coinC;
			C = C % coinC;
		}
	}

	for (int i = 0; i < cnt.size(); i++)
	{
		cout << cnt[i] << " ";
	}

	cout << endl;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		func();
	}

	return 0;
}