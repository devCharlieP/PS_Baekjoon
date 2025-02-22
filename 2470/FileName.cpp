#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	int plus = INT_MAX;
	int res_1 = 0;
	int res_2 = 0;

	for (int i = 0; i < N - 1; i++)
	{
		int left = i + 1;
		int right = N - 1;
		int mid = 0;

		bool b = false;

		while (left <= right)
		{
			mid = (left + right) / 2;

			if (abs(vec[i] + vec[mid]) < plus)
			{
				plus = abs(vec[i] + vec[mid]);

				res_1 = vec[i];
				res_2 = vec[mid];
			}

			if (vec[i] + vec[mid] == 0)
			{
				b = true;
				break;
			}
			else if (vec[i] + vec[mid] < 0)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		if (b)
			break;
	}

	cout << res_1 << " " << res_2;

	return 0;
}