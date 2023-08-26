#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

vector<bool> vec(1000001, true);

void era()
{
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (vec[i] == true)
		{
			for (int j = i * i; j <= 1000000; j += i)
			{
				vec[j] = false;
			}
		}
	}
}

void fun()
{
	int N;
	cin >> N;

	int cnt = 0;

	for (int i = 2; i <= N / 2; i++)
	{
		if (vec[i] == true && vec[N - i] == true)
		{
			cnt++;
		}
	}

	cout << cnt << endl;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	era();

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		fun();
	}

	return 0;
}