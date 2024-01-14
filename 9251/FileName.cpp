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

	string s1, s2;
	cin >> s1 >> s2;

	vector<vector<int>> vec(1001, vector<int>(1001));

	for (int i = 1; i <= s1.size(); i++)
	{
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				vec[i][j] = vec[i - 1][j - 1] + 1;
			}
			else
			{
				vec[i][j] = max(vec[i - 1][j], vec[i][j - 1]);
			}
		}
	}

	cout << vec[s1.size()][s2.size()];

	return 0;
}