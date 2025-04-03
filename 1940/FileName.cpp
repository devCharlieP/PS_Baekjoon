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

	int N, M;
	cin >> N >> M;

	vector<int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	int left = 0;
	int right = vec.size() - 1;

	int res = 0;

	while (left < right)
	{
		int sum = vec[left] + vec[right];

		if (sum == M)
		{
			res++;
			left++;
			right--;
		}
		else if (sum < M)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout << res;

	return 0;
}