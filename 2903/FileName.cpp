#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vec(16);

	vec[1] = 3;

	for (int i = 2; i < 16; i++)
	{
		vec[i] = 2 * vec[i - 1] - 1;
	}

	cout << vec[N] * vec[N];

	return 0;
}