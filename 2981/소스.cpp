#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
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

	vector <int> M;

	vector <int> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	vector <int> tmp;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			tmp.push_back(abs(vec[i] - vec[j]));
		}
	}

	int num = tmp[0];

	if (tmp.size() != 1)
	{
		for (int i = 0; i < N - 1; i++)
		{
			num = gcd(num, tmp[i + 1]);
		}
	}	

	for (int i = 1; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			M.push_back(i);

			if (i != (num / i))
			{
				M.push_back(num / i);
			}
		}
	}

	sort(M.begin(), M.end());

	for (int i = 1; i < M.size(); i++)
	{
		cout << M[i] << " ";
	}

	return 0;
}