#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int max(int a, int b, int c)
{
	int maxNum = 0;

	if (a > b)
	{
		if (a > c)
		{
			maxNum = a;
		}
		else
		{
			maxNum = c;
		}
	}
	else
	{
		if (b > c)
		{
			maxNum = b;
		}
		else
		{
			maxNum = c;
		}
	}

	return maxNum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;

	int res = 0;

	if (A == B && A == C && B == C)
	{
		res = 10000 + (A * 1000);
	}
	else if (A != B && A != C && B != C)
	{
		res = max(A, B, C) * 100;
	}
	else
	{
		if (A == B)
		{
			res = 1000 + (A * 100);
		}
		else
		{
			res = 1000 + (C * 100);
		}
	}

	cout << res;

	return 0;
}