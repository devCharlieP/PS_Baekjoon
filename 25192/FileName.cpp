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

	map<string, int> gomgom;

	string temp;
	int res = 0;

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;

		if (temp == "ENTER")
		{
			res += gomgom.size();
			gomgom.clear();
		}
		else
		{
			gomgom.insert({ temp, 0 });
		}
	}

	res += gomgom.size();

	cout << res;

	return 0;
}