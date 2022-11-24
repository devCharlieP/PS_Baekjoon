#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#define endl '\n'
using namespace std;

struct Res
{
	int is;
	int cnt;
};

Res rec(const char* s, int l, int r, int cnt)
{
	if (l >= r)
	{
		return Res{1, cnt};
	}
	else if (s[l] != s[r])
	{
		return Res{0, cnt};
	}
	else
	{
		return rec(s, l + 1, r - 1, cnt + 1);
	}
}

Res isPal(const char* s)
{
	return rec(s, 0, strlen(s) - 1, 1);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	char s[1001];

	for (int i = 1; i <= T; i++)
	{
		cin >> s;

		Res result = isPal(s);

		cout << result.is << " " << result.cnt << endl;
	}

	return 0;
}