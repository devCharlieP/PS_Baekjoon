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

	string s;
	cin >> s;

	bool b = 1;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != s[s.size() - 1 - i])
		{
			b = 0;
			break;
		}
	}

	cout << b;

	return 0;
}