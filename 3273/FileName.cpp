#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	set<int> s;

	int temp;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		s.insert(temp);
	}

	int x;
	cin >> x;

	int cnt = 0;

	while (!s.empty())
	{
		auto ptr = s.find(x - *s.begin());

		if (ptr != s.end() && *ptr != x / 2)
		{
			cnt++;
			s.erase(ptr);
			s.erase(s.begin());
		}
		else
		{
			s.erase(s.begin());
		}
	}

	cout << cnt;

	return 0;
}