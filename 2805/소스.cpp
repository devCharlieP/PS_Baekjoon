#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector <int> vec(N + 1);
	int max = -98754321;

	for (int i = 1; i <= N; i++)
	{
		cin >> vec[i];

		if (vec[i] > max)
		{
			max = vec[i];
		}
	}

	int min = 0;
	int mid = 0;

	while (min < max)
	{
		mid = (min + max) / 2;
		long long tree = 0;

		for (int i = 1; i <= N; i++)
		{
			long long temp = vec[i] - mid;

			if (temp > 0)
			{
				tree += temp;
			}
		}

		if (tree < M)
		{
			max = mid - 1;
		}
		else if (tree >= M)
		{
			min = mid + 1;
		}
	}

	cout << mid - 1;

	return 0;
}