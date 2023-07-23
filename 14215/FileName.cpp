#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a;
	int max_a = -1;
	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> a;
		max_a = max(max_a, a);
		sum += a;
	}

	sum -= max_a;

	if (sum > max_a)
	{
		cout << sum + max_a;
	}
	else
	{
		cout << sum + sum - 1;
	}

	return 0;
}