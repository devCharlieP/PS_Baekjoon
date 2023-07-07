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

	vector <string> str(5);

	for (int i = 0; i < 5; i++)
	{
		cin >> str[i];
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i < str[j].size())
			{
				cout << str[j][i];
			}
		}
	}

	return 0;
}