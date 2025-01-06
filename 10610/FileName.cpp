#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	vector<int> vec;

	for (int i = 0; i < s.size(); i++)
	{
		vec.push_back(s[i] - '0');
	}

	sort(vec.begin(), vec.end(), greater<int>());

	if (vec[vec.size() - 1] != 0)
	{
		cout << -1;
	}
	else
	{
		long long sum = 0;

		for (int i = 0; i < vec.size(); i++)
		{
			sum += vec[i];
		}

		if (sum % 3 == 0)
		{
			for (int i = 0; i < vec.size(); i++)
			{
				cout << vec[i];
			}
		}
		else
		{
			cout << -1;
		}
	}	

	return 0;
}