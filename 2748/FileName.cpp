#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<long long> vec(n + 1);
	vec[0] = 0;
	vec[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		vec[i] = vec[i - 1] + vec[i - 2];
	}

	cout << vec[n];

	return 0;
}