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

	int N, K;
	cin >> N >> K;

	int cnt = 1;
	int res = 0;

	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			if (cnt == K)
			{
				res = i;
				break;
			}
			else
			{
				cnt++;
			}
		}
	}

	cout << res;

	return 0;
}