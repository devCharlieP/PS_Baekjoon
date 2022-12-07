#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;

	map<string, int> map;
	string subString;

	for (int i = 1; i <= S.size(); i++)
	{
		for (int j = 0; j <= S.size() - i; j++)
		{
			subString = S.substr(j, i);

			map.insert({ subString, 0 });
		}
	}

	cout << map.size();

	return 0;
}