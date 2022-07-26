#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long N, M;
	cin >> N >> M;

	long long res = abs(N - M);

	cout << res;

	return 0;
}