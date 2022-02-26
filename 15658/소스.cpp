#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector <int> vec;
	vector <int> idx;
	string temp = "abcd";
	string per;

	for (int i = 0; i < n; i++)
	{
		int push;
		cin >> push;
		vec.push_back(push);
	}

	for (int i = 0; i < 4; i++)
	{
		int push;
		cin >> push;

		for (int j = 0; j < push; j++)
		{
			per.push_back(temp[i]);
		}
	}

	vector <int> vec01(per.size(), 1);
	for (int i = 0; i < n - 1; i++)
	{
		vec01[i] = 0;
	}

	int min = 2147483647;
	int max = -2147483648;

	do
	{
		string per_x;

		for (int i = 0; i < vec01.size(); i++)
		{
			if (vec01[i] == 0)
			{
				per_x.push_back(per[i]);
			}
		}

		do
		{
			int result = vec[0];

			for (int i = 0; i < n - 1; i++)
			{
				if (per_x[i] == 'a')
				{
					result += vec[i + 1];
				}
				else if (per_x[i] == 'b')
				{
					result -= vec[i + 1];
				}
				else if (per_x[i] == 'c')
				{
					result *= vec[i + 1];
				}
				else if (per_x[i] == 'd')
				{
					result /= vec[i + 1];
				}
			}

			if (min > result)
			{
				min = result;
			}

			if (max < result)
			{
				max = result;
			}

		} while (next_permutation(per_x.begin(), per_x.end()));
		
	} while (next_permutation(vec01.begin(), vec01.end()));

	printf("%d\n%d", max, min);

	return 0;
}