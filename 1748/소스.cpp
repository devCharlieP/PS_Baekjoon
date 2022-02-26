#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int cnt = 0;
	int temp = n;
	
	while (temp >= 1)
	{
		temp /= 10;
		cnt++;
	}

	int sum = 0;
	int num_9 = 1;

	for (int i = 1; i <= cnt - 1; i++)
	{
		sum += i * (9 * num_9);
		num_9 *= 10;	
	}

	num_9 = num_9 - 1;

	cout << sum + (cnt * (n - num_9));

	return 0;
}