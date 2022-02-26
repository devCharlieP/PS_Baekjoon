#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector <int>> vec;
int max_t = numeric_limits<int>::min();
int i_1 = -1, j_1 = -1;

int tetro(int i, int j, int count, int sum)
{
	if (i < 0 || i >= vec.size() || j < 0 || j >= vec[i].size() || (i == i_1 && j == j_1))
	{
		count++;
	}
	else
	{
		i_1 = i;
		j_1 = j;
		sum += vec[i][j];
		count++;
	}

	if (count == 4)
	{
		if (max_t < sum)
		{
			max_t = sum;
		}
		return sum;
	}

	sum = tetro(i + 1, j, count, sum) + tetro(i - 1, j, count, sum) + tetro(i, j + 1, count, sum) + tetro(i, j - 1, count, sum);

	return max_t;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		vector <int> vec1;

		for (int j = 0; j < m; j++)
		{
			int push;
			cin >> push;
			vec1.push_back(push);
		}

		vec.push_back(vec1);
	}

	int max = numeric_limits<int>::min();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp = tetro(i, j, 0, 0);

			if (max < temp)
			{
				max = temp;
			}
		}
	}

	cout << max;


	return 0;
}