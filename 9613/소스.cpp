#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <vector <int>> vec;
	vector <long long> out;

	for (int i = 0; i < n; i++)
	{
		int n2;
		cin >> n2;

		vector <int> vec2;

		for (int j = 0; j < n2; j++)
		{
			int n3;
			cin >> n3;
			vec2.push_back(n3);
		}

		vec.push_back(vec2);
	}

	for (int i = 0; i < n; i++)
	{
		long long sum = 0;
		int vec_in = 0;

		for (int j = 0; j < vec[i].size() - 1; j++)
		{
			for (int k = j + 1; k < vec[i].size(); k++)
			{
				int min_in = min(vec[i][j], vec[i][k]);
				int max_in = max(vec[i][j], vec[i][k]);
				
				while (1)
				{
					if (max_in % min_in == 0)
					{
						vec_in = min_in;
						break;
					}
					else
					{
						int temp;
						temp = min_in;
						min_in = max_in % min_in;
						max_in = temp;
					}
				}
				
				sum += vec_in;
			}
		}

		out.push_back(sum);
	}

	for (int i = 0; i < out.size(); i++)
	{
		cout << out[i] << '\n';
	}

	return 0;
}