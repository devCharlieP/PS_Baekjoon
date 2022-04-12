#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector <int> vec(N);
	vector <int> res(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		res[i] = sum + vec[i];
		sum += vec[i];
	}

	int res_sum = 0;

	for (int i = 0; i < N; i++)
	{
		res_sum += res[i];
	}

	cout << res_sum;

	return 0;
}