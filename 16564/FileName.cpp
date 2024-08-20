#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> X(N);

	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
	}

	sort(X.begin(), X.end());

	int pt = X[0];
	int res = 0;

	while (1)
	{
		auto lower = lower_bound(X.begin(), X.end(), pt);
		auto upper = upper_bound(X.begin(), X.end(), pt);

		int num = (upper - X.begin()) - (lower - X.begin());

		if (upper == X.end())
		{
			res = pt + (K / num);
			break;
		}

		int upK = num * (*upper - pt);

		if (upK > K)
		{
			res = pt + (K / num);
			break;
		}
		else
		{
			K -= upK;

			for (auto pt = lower; pt != upper; pt++)
			{
				*pt = *upper;
			}

			pt = *upper;
		}
	}

	cout << res;

	return 0;
}