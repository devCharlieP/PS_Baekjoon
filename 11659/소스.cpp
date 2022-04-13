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

	int N, M;
	cin >> N >> M;

	vector <int> vec(100001);
	for (int i = 1; i <= N; i++)
	{
		cin >> vec[i];
	}

	int sum = 0;
	vector <int> vec_sum(100001);
	for (int i = 1; i <= N; i++)
	{
		sum += vec[i];
		vec_sum[i] = sum;
	}

	vector <int> vec_res;
	for (int i = 1; i <= M; i++)
	{
		int x, y;
		cin >> x >> y;
		vec_res.push_back(vec_sum[y] - vec_sum[x - 1]);
	}

	for (int i = 0; i < M; i++)
	{
		cout << vec_res[i] << endl;
	}

	return 0;
}