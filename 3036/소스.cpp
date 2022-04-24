#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector <int> vec;

	for (int i = 1; i <= N; i++)
	{
		int push;
		cin >> push;
		vec.push_back(push);
	}

	int n_gcd = 0;

	for (int i = 1; i < N; i++)
	{
		n_gcd = gcd(max(vec[0], vec[i]), min(vec[0], vec[i]));

		cout << vec[0] / n_gcd << "/" << vec[i] / n_gcd << endl;
	}

	return 0;
}