#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define endl "\n"
using namespace std;

void func()
{
	int N;
	cin >> N;

	set<pair<int, int>> s;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		s.insert({ a, b });
	}

	pair<int, int> top = *s.begin();
	s.erase(s.begin());

	int cnt = 1;

	for (auto ptr = s.begin(); ptr != s.end(); ptr++)
	{
		if (top.second > ptr->second)
		{
			top = *ptr;
			cnt++;
		}
	}

	cout << cnt << endl;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		func();
	}

	return 0;
}