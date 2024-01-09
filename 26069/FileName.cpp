#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	map <string, int> ch;
	ch.insert({ "ChongChong", 0 });

	string s1, s2;

	for (int i = 1; i <= N; i++)
	{
		cin >> s1 >> s2;

		if (ch.find(s1) != ch.end())
		{
			ch.insert({ s2, 0 });
		}
		else if(ch.find(s2) != ch.end())
		{
			ch.insert({ s1, 0 });
		}
	}

	cout << ch.size();

	return 0;
}