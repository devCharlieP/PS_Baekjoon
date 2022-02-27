#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N_cnt;
	cin >> N_cnt;

	vector <int> N_vec(N_cnt);

	for (int i = 0; i < N_cnt; i++)
	{
		cin >> N_vec[i];
	}

	int N_max = -987654321;
	int N_min = 987654321;

	for (int i = 0; i < N_cnt; i++)
	{
		N_max = max(N_max, N_vec[i]);
		N_min = min(N_min, N_vec[i]);
	}

	cout << N_max * N_min;

	return 0;
}