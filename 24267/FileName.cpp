#include <iostream>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	long long cnt = 0;
	long long sum = 0;

	for (int i = 1; i <= n - 2; i++)
	{
		sum += i;
		cnt += sum;
	}

	cout << cnt << endl << 3;

	return 0;
}