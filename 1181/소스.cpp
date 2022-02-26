#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <string> arr(n);
	vector <string> result;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	
	int max = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (max < arr[i].size())
		{
			max = arr[i].size();
		}
	}

	for (int i = 1; i <= max; i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j].size() == i)
			{
				result.push_back(arr[j]);
			}
		}		
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}