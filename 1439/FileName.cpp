#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	vector<int> cnt(2);
	int temp = s[0] - '0';

	for (int i = 1; i < s.size(); i++)
	{
		if (temp != (s[i] - '0'))
		{
			cnt[temp]++;
			temp = s[i] - '0';
		}
	}

	cnt[temp]++;

	cout << min(cnt[0], cnt[1]);

	return 0;
}