#include <iostream>
#include <algorithm>
#include <vector>
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

	int res = 0;

	for (int i = 0; i < N; i++)
	{
		int sum = 0;

		for (int j = i; j < N; j++)
		{
			sum += vec[j];

			if (sum == M)
			{
				res++;
				break;
			}
			else if (sum > M)
			{
				break;
			}
		}
	}

	cout << res;

	return 0;
}