#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long N;
	cin >> N;

	long long k;
	cin >> k;

	long long res = 0;

	long long left = 1;
	long long right = N * N;

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		long long cnt = 0;

		for (long long i = 1; i <= N; i++)
		{
			cnt += min(mid / i, N);
		}

		if (cnt >= k)
		{
			res = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << res;

	return 0;
}