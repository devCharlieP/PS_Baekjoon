#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	string s;
	cin >> s;

	int i = 0;
	int cnt = 0;
	int res = 0;

	while (i < (M - 1))
	{
		if (s.substr(i, 3) == "IOI")
		{
			i += 2;
			cnt += 1;

			if (cnt == N)
			{
				res += 1;
				cnt -= 1;
			}
		}
		else
		{
			i += 1;
			cnt = 0;
		}
	}

	cout << res;

	return 0;
}