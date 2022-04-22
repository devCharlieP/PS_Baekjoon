#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, C;

	cin >> A >> B;
	cin >> C;

	int res_A = 0, res_B = 0;

	res_A = A + (B + C) / 60;
	res_B = (B + C) % 60;

	if (res_A >= 24)
	{
		res_A -= 24;
	}

	cout << res_A << " " << res_B;

	return 0;
}