#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int N;
vector <int> vec;

void sansool()
{
	double sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum += vec[i];
	}

	if (round(sum / double(N)) == -0)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << round(sum / double(N)) << endl;
	}
}

void jungang()
{
	cout << vec[N / 2] << endl;
}

void choibin()
{
	vector <int> res;

	int num = 1;
	int max = numeric_limits<int>::min();

	if (vec.size() == 1)
	{
		cout << vec[0] << endl;
		return;
	}

	vec.push_back(4001);

	for (int i = 0; i < N; i++)
	{
		if (vec[i] == vec[i + 1])
		{
			num++;
		}
		else
		{
			if (max < num)
			{
				max = num;
				res.clear();
				res.push_back(vec[i]);
			}
			else if (max == num)
			{
				res.push_back(vec[i]);
			}

			num = 1;
		}
	}

	vec.pop_back();
	
	if (res.size() == 1)
	{
		cout << res[0] << endl;
	}
	else
	{
		cout << res[1] << endl;
	}
}

void scope()
{
	cout << vec[N - 1] - vec[0] << endl;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	vec = vector <int>(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	sansool();
	jungang();
	choibin();
	scope();

	return 0;
}