#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, C;

	cin >> N >> C;

	vector<int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	int left = 1;
	int right = vec[N - 1] - vec[0];

	int res = -1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		int cnt = 1;
		int pre = vec[0];

		for (int i = 1; i < N; i++)
		{
			if (vec[i] - pre >= mid)
			{
				cnt++;
				pre = vec[i];
			}
		}

		if (C <= cnt)
		{
			res = max(res, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << res;

	return 0;
}