#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl "\n"
using namespace std;

int K, N;
vector <long long> vec(10001);

int check(long long mid)
{
	long long value = 0;

	for (int i = 1; i <= K; i++)
	{
		value += vec[i] / mid;
	}

	if(value >= N)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> K >> N;

	for (int i = 1; i <= K; i++)
	{
		cin >> vec[i];
	}

	long long max = 0;
	for (int i = 1; i <= K; i++)
	{
		if (vec[i] > max)
		{
			max = vec[i];
		}
	}

	long long start = 1;
	long long end = max;
	long long mid = 0;

	while(start <= end)
	{
		mid = (start + end) / 2;

		if (check(mid) == 1)
		{
			start = mid + 1;
		}
		else if(check(mid) == 0)
		{
			end = mid - 1;
		}
	}

	cout << start - 1;

	return 0;
}