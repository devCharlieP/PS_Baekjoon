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

	vector<int> rope(N);

	for (int i = 0; i < N; i++)
	{
		cin >> rope[i];
	}

	sort(rope.begin(), rope.end());
	
	int res = INT_MIN;

	for (int i = 0; i < N; i++)
	{
		res = max(res, rope[i] * (N - i));
	}

	cout << res;

	return 0;
}