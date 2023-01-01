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

	int N;
	cin >> N;

	vector<int> s(1000001);

	s[1] = 1;
	s[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		s[i] = (s[i - 2] + s[i - 1]) % 15746;
	}

	cout << s[N];

	return 0;
}