#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vec(31);
	vec[0] = 1;
	vec[1] = 0;
	vec[2] = 3;

	for (int i = 4; i <= 30; i += 2)
	{
		for (int j = 0; j < i - 2; j += 2)
		{
			vec[i] += vec[j] * 2;
		}

		vec[i] += vec[i - 2] * 3;
	}

	cout << vec[N];

	return 0;
}