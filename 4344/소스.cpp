#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

void fun()
{
	int n;
	cin >> n;
	
	vector<int> vec(n);

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		sum += vec[i];
	}

	int avg = sum / n;

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (avg < vec[i])
		{
			cnt++;
		}
	}

	double per = double(cnt) / double(n) * 100;

	cout << fixed;
	cout.precision(3);
	cout << per << "%" << endl;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		fun();
	}

	return 0;
}