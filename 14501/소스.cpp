#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <int> T(1);
	vector <int> P(1);

	for (int i = 0; i < n; i++)
	{
		int push1, push2;
		cin >> push1 >> push2;
		T.push_back(push1);
		P.push_back(push2);
	}

	vector <int> dp(n + 1, numeric_limits<int>::min());

	for (int i = 1; i <= n; i++)
	{
		for (int j = T[i] + 1; j <= n; j++)
		{
			dp[j] = max(dp[j], dp[j]+ P[j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << " ";
	}

	return 0;
}