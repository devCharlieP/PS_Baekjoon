#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

string rec(int N, string s)
{
	if (N == 0)
	{
		return s;
	}
	else
	{
		string s1 = s.substr(0, pow(3, N) / 3);
		string s2 = s.substr(pow(3, N) * 2 / 3, pow(3, N));
		string s3;

		for (int i = 1; i <= pow(3, N) / 3; i++)
		{
			s3.push_back(' ');
		}

		return rec(N - 1, s1) + s3 + rec(N - 1, s2);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;

	while (cin >> N)
	{
		string s;

		for (int i = 1; i <= pow(3, N); i++)
		{
			s.push_back('-');
		}

		cout << rec(N, s) << endl;
	}

	return 0;
}