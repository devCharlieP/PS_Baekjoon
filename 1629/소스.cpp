#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

long long dc(long long A, long long B, long long C)
{
	if (B == 1)
	{
		return A % C;
	}
	else
	{
		long long temp = 0;
		temp = dc(A, B / 2, C);

		temp = temp * temp % C;

		if (B % 2 == 0)
		{
			return temp;
		}
		else
		{
			return (temp * A) % C;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long A, B, C;
	cin >> A >> B >> C;

	cout << dc(A, B, C);

	return 0;
}