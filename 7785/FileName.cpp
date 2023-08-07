#include <iostream>
#include <string>
#include <set>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	set<string, greater<string>> m;

	for (int i = 1; i <= n; i++)
	{
		string name, EL;
		cin >> name >> EL;

		if (EL == "enter")
		{
			m.insert(name);
		}
		else
		{
			m.erase(name);
		}
	}

	for (const auto& i : m)
	{
		cout << i << endl;
	}

	return 0;
}