#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	string s = to_string(N);

	vector<int> vec(10);

	bool b = false;

	for (int i = 0; i < s.size(); i++)
	{
		int n = s[i] - '0';

		if (n == 6 || n == 9)
		{
			if (b)
			{
				b = false;
				vec[9]++;
			}
			else
			{
				b = true;
				vec[6]++;
			}
		}
		else
		{
			vec[n]++;
		}
	}

	int res = 0;

	for (int i = 0; i < 10; i++)
	{
		res = max(res, vec[i]);
	}

	cout << res;

	return 0;
}