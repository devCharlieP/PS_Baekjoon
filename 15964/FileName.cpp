#include <iostream>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long A, B;
	cin >> A >> B;

	long long res = (A + B) * (A - B);

	cout << res;

	return 0;
}