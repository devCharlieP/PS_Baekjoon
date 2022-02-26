#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int count(int x, int y)
{
	int cnt = 0;

	for (long long i = y; x / i >= 1; i *= y)
	{
		cnt += x / i;
	}

	return cnt;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int sum_2 = 0, sum_5 = 0;

	sum_2 += count(n, 2);
	sum_2 -= count(m, 2);
	sum_2 -= count(n - m, 2);

	sum_5 += count(n, 5);
	sum_5 -= count(m, 5);
	sum_5 -= count(n - m, 5);

	cout << min(sum_2, sum_5);

	return 0;
}