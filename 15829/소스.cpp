#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

#define endl '\n'
using namespace std;

int alp(char c)
{
	string alp_all = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < alp_all.size(); i++)
	{
		if (c == alp_all[i])
		{
			return i + 1;
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int L;
	cin >> L;

	string s;
	cin >> s;

	unsigned long long M = 1234567891;
	unsigned long long sum = 0;

	for (int i = 0; i < s.size(); i++)
	{
		unsigned long long mul = 1;

		for (int j = 0; j < i; j++)
		{
			mul = (mul * 31) % M;
		}

		sum = (sum + (alp(s[i]) * mul) % M) % M;
	}

	cout << sum;

	return 0;
}