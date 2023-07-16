#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

void func(int n)
{
	vector<int> vec;

	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			vec.push_back(i);
		}
	}

	int sum = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		sum += vec[i];
	}
		
	if (sum == n)
	{
		cout << n << " = ";

		for (int i = 0; i < vec.size(); i++)
		{
			if (i != vec.size() - 1)
			{
				cout << vec[i] << " + ";
			}
			else
			{
				cout << vec[i] << endl;
			}
		}
	}
	else
	{
		cout << n << " is NOT perfect." << endl;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	while (1)
	{
		cin >> n;

		if (n == -1)
			break;

		func(n);
	}

	return 0;
}