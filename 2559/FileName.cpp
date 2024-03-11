#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	int plus = 0;
	for (int i = 0; i < K; i++)
	{
		plus += vec[i];
	}

	int left = 0, right = K;
	int res = plus;
	for (int i = 0; i < N - K; i++)
	{
		plus = plus - vec[left] + vec[right];
		res = max(res, plus);
		left++;
		right++;
	}

	cout << res;

	return 0;
}