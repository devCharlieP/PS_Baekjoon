#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		int n;
		cin >> n;

		vector <string> vec;

		for (int i = 1; i <= n; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			
			vec.push_back(s2);
		}

		sort(vec.begin(), vec.end());

		set<string> fashion;

		int cnt = 0;
		int sav = 0;

		for (int i = 0; i < n; i++)
		{
			if (fashion.find(vec[i]) == fashion.end())
			{
				fashion.insert(vec[i]);
				sav = cnt;
				cnt = 2 * cnt + 1;
			}
			else
			{
				cnt = cnt + sav + 1;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}