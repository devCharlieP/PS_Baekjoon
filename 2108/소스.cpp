#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	//»ê¼úÆò±Õ
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	cout << fixed;
	cout.precision(0);
	cout << sum / double(n) << "\n";

	//Áß¾Ó°ª
	cout << arr[n / 2] << "\n";

	//ÃÖºó°ª
	int num = 1;
	vector <int> res;

	arr.push_back(NULL);

	for (int i = 0; i < n; i++)
	{			
		if (arr[i] == arr[i + 1])
		{
			num++;
		}
		else
		{
			res.push_back(num);
			num = 1;
		}
	}
	arr.pop_back();

	int max = numeric_limits<int>::min();
	for (int i = 0; i < res.size(); i++)
	{
		if (max < res[i])
		{
			max = res[i];
		}
	}

	int num_s = 0;
	vector<int> j;
	for (int i = 0; i < res.size(); i++)
	{
		if (max == res[i])
		{
			j.push_back(i);
			num_s++;
		}
		if (j.size() > 1)
		{
			break;
		}
	}

	if (num_s > 1)
	{
		int sum_1 = 0;
		for (int i = 0; i < j[1]; i++)
		{
			sum_1 += res[i];
		}
		cout << arr[sum_1] << "\n";
	}
	else
	{
		int sum_1 = 0;
		for (int i = 0; i < j[0]; i++)
		{
			sum_1 += res[i];
		}
		cout << arr[sum_1] << "\n";
	}
	
	//¹üÀ§
	cout << arr[n - 1] - arr[0] << "\n";

	return 0;
}