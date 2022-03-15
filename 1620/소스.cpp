#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	map<string, int> pokemon_dogam;

	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;

		pokemon_dogam.insert({ s, i });
	}

	for (int i = 1; i <= M; i++)
	{
		string s;
		cin >> s;

		if (s[0] - '0' >= 0 && s[0] - '0' <= 9)
		{
			int num = 0;
			stringstream ssInt(s);
			ssInt >> num;

			cout << pokemon_dogam[num] << endl;
		}
		else
		{
			for (int j = 1; j <= N; j++)
			{
				if (pokemon_dogam[j] == s)
				{
					cout << j << endl;
					break;
				}
			}
		}
	}

	return 0;
}