#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int GCD(int A, int B)
{
	if (B == 0)
	{
		return A;
	}
	else
	{
		return GCD(B, A % B);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long A, B;
	cin >> A >> B;

	int G = GCD(max(A, B), min(A, B));

	cout << A * B / G;

	return 0;
}