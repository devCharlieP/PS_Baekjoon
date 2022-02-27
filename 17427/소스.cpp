#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> F_vec(1000001);

long long G(int n)
{
	long long sum = 0;

	for (int i = 1; i <= n; i++)
	{
		long long num = n / i;
		sum += i * num;
	}

	return sum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << G(n);

	return 0;
}