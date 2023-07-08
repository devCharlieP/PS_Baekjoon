#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string N;
	int B;
	cin >> N >> B;

	long long res = 0;

	for (int i = 0; i < N.size(); i++)
	{
		if (N[i] >= '0' && N[i] <= '9')
		{
			res += (N[i] - '0') * pow(B, N.size() - i - 1);
		}
		else
		{
			res += (N[i] - 'A' + 10) * pow(B, N.size() - i - 1);
		}
	}

	cout << res;

	return 0;
}