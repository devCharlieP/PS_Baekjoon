#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vec(1001);
vector <int> dp_vec(1001, 10001);

int dp(int N)
{
	if (N == 1)
	{
		return vec[N];
	}

	if (dp_vec[N] != 10001)
	{
		return dp_vec[N];
	}

	for (int i = 1; i <= N / 2; i++)
	{
		dp_vec[N] = min(dp_vec[N], dp(i) + dp(N - i));
	}

	return dp_vec[N] = min(dp_vec[N], vec[N]);
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> vec[i];
	}

	cout << dp(N);

	return 0;
}