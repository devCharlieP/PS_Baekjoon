#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	long long temp, sum = 0;
	vector <long long> mod(m + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		sum += temp;
		mod[sum % m]++;
	}

	long long cnt = 0;

	for (int i = 0; i < m; i++)
	{
		cnt += (mod[i] * (mod[i] - 1)) / 2;
	}

	cout << cnt + mod[0];

	return 0;
}