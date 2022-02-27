#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> F_vec(1000001);
vector <long long> G_vec(1000001);

void F()
{

	for (int i = 1; i <= 1000000; i++)
	{
		for (int j = i; j <= 1000000; j += i)
		{
			F_vec[j] += i;
		}
	}
}

void G()
{
	F();

	long long sum = 0;

	for (int i = 1; i <= 1000000; i++)
	{
		sum += F_vec[i];
		G_vec[i] = sum;
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	G();

	int cnt = 0;
	cin >> cnt;

	for (int i = 1; i <= cnt; i++)
	{
		int n;
		cin >> n;

		cout << G_vec[n];
		cout << "\n";
	}
	
	return 0;
}