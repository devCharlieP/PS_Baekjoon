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

	int M = 1234567891;
	int sum = 0;

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			(31 * j) % M;
		}
		//sum += (alp(s[i])* pow(31, i)) % M;
	}

	cout << (sum) % M;

	return 0;
}