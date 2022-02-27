#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n;
vector <char> vec(11);
vector <int> ch(11);
vector <int> arr;

long long maxi = -9999999999;
vector <int> vec_max;

long long mini = 9999999999;
vector <int> vec_min;

void dfs(int L, int x)
{
	if (L == n)
	{
		long long sum = 0;

		for (int i = 0; i < arr.size(); i++)
		{
			sum += pow(10, i) * arr[arr.size() - 1 - i];
		}

		if (sum > maxi)
		{
			maxi = sum;
			vec_max = arr;
		}
		
		if (sum < mini)
		{
			mini = sum;
			vec_min = arr;
		}
		
		return;
	}
	else
	{
		for (int j = 0; j <= 9; j++)
		{
			if (ch[j] == 0)
			{
				ch[j] = 1;

				if (vec[L] == '<')
				{
					if (x < j)
					{
						arr.push_back(j);
						dfs(L + 1, j);
						arr.pop_back();
					}
				}
				else
				{
					if (x > j)
					{
						arr.push_back(j);
						dfs(L + 1, j);
						arr.pop_back();
					}
				}

				ch[j] = 0;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	for (int i = 0; i <= 9; i++)
	{
		arr.push_back(i);
		ch[i] = 1;

		dfs(0, i);

		ch[i] = 0;
		arr.pop_back();
	}

	for (int i = 0; i < vec_max.size(); i++)
	{
		cout << vec_max[i];
	}
	cout << endl;

	for (int i = 0; i < vec_min.size(); i++)
	{
		cout << vec_min[i];
	}

	return 0;
}