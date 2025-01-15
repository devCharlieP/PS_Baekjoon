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

	vector<int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	cout << vec[K - 1];

	return 0;
}