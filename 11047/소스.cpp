#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector <int> coin(12, 100000001);

	for (int i = 1; i <= N; i++)
	{
		cin >> coin[i];
	}

	int cnt = 0;

	while (K != 0)
	{
		for (int i = 1; i <= N; i++)
		{
			if (coin[i] <= K && coin[i + 1] > K)
			{
				cnt += (K / coin[i]);
				K = (K % coin[i]);
				break;
			}
		}
	}

	cout << cnt;
	return 0;
}