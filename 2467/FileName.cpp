#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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

	int left = 0;
	int right = N - 1;

	int zeroSum = INT_MAX;

	int res1 = 0, res2 = 0;

	while (left < right)
	{
		int sum = vec[left] + vec[right];

		if (abs(sum) <= zeroSum)
		{
			zeroSum = abs(sum);
			res1 = vec[left];
			res2 = vec[right];
		}

		if (sum < 0)
		{
			left++;
		}
		else if (sum > 0)
		{
			right--;
		}
		else
		{
			break;
		}
	}

	cout << res1 << " " << res2;

	return 0;
}