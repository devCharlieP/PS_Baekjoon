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

	vector<string> vec_pokemon_dogam(1);

	map<string, int> pokemon_dogam;

	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;

		vec_pokemon_dogam.push_back(s);
		pokemon_dogam.insert({ s, i });
	}
	
	map<string, int>::iterator iter;

	for (int i = 1; i <= M; i++)
	{
		string s;
		cin >> s;

		if (s[0] - '0' >= 0 && s[0] - '0' <= 9)
		{
			int num = 0;
			stringstream ssInt(s);
			ssInt >> num;

			cout << vec_pokemon_dogam[num] << endl;
		}
		else
		{
			iter = pokemon_dogam.find(s);
			cout << iter->second << endl;
		}
	}

	return 0;
}