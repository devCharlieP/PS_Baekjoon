#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vec(N + 1);
	vec[1] = 3;
	vec[2] = 7;

	for (int i = 3; i <= N; i++)
	{
		vec[i] = (vec[i - 2] % 9901) + (2 * (vec[i - 1] % 9901));
	}

	cout << vec[N] % 9901;

	return 0;
}