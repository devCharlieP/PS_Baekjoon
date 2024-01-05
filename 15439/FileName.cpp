#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	cout << N * (N - 1);

	return 0;
}