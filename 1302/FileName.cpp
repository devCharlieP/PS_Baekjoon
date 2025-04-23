#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	map<string, int> m;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		auto pt = m.find(s);

		if (m.empty() || pt == m.end())
		{
			m.insert({ s, 0 });
		}
		else
		{
			pt->second += 1;
		}
	}

	string res;
	int cnt = -1;

	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		if (cnt < iter->second)
		{
			res = iter->first;
			cnt = max(cnt, iter->second);
		}
		else if (cnt == iter->second)
		{
			if (res > iter->first)
			{
				res = iter->first;
			}
		}
	}

	cout << res;

	return 0;
}