#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long S;
	cin >> S;

	long long res = 0;
	long long sum = 0;

	for (long long i = 1; i <= 4294967295; i++)
	{
		sum += i;

		if (sum > S)
		{
			res = i - 1;
			break;
		}
	}

	cout << res;

	return 0;
}