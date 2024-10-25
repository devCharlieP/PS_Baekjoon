#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> region(N);
	for (int i = 0; i < N; i++)
	{
		cin >> region[i];
	}
	
	int M;
	cin >> M;

	sort(region.begin(), region.end());

	int res = 0;
	bool b = false;

	for (int i = 0; i < N; i++)
	{
		if (region[i] > M / (N - i))
		{
			res = M / (N - i);
			b = true;

			break;
		}

		M -= region[i];
	}

	if (b)
	{
		cout << res;
	}
	else
	{
		cout << region[N - 1];
	}

	return 0;
}