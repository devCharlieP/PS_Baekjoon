#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

	int n, s;
	cin >> n >> s;

	vector <int> vec;

	for (int i = 0; i < n; i++)
	{
		int push;
		cin >> push;
		vec.push_back(push);
	}

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		vector<int> com(n, 0);

		for (int j = 0; j <= i; j++)
		{
			com[j] = 1;
		}

		sort(com.begin(), com.end());

		do
		{
			int sum = 0;

			for (int j = 0; j < n; j++)
			{
				if (com[j] == 1)
				{
					sum += vec[j];
				}
			}

			if (sum == s)
			{
				cnt++;
			}

		} while (next_permutation(com.begin(), com.end()));
	}
	
	cout << cnt;

	return 0;
}