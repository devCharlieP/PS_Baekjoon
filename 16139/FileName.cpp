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

	string S;
	cin >> S;

	int q;
	cin >> q;

	string abc = "abcdefghijklmnopqrstuvwxyz";
	vector<vector<int>>vec(abc.size(), vector<int>(S.size()));

	for (int i = 0; i < abc.size(); i++)
	{
		int cnt = 0;

		for (int j = 0; j < S.size(); j++)
		{
			if (S[j] == abc[i])
			{
				cnt++;
			}

			vec[i][j] = cnt;
		}
	}

	char a;
	int l, r;

	for (int i = 0; i < q; i++)
	{
		cin >> a >> l >> r;

		int pt = a - 'a';

		if (S[l] == a)
		{
			cout << vec[pt][r] - vec[pt][l] + 1 << endl;
		}
		else
		{
			cout << vec[pt][r] - vec[pt][l] << endl;
		}
	}

	return 0;
}