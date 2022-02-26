#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;

	string save;
	vector<int> arr(0);

	int max = numeric_limits<int>::min();
	int stack = 0;
	int num = 0;

	transform(s.begin(), s.end(), s.begin(), (int(*)(int))toupper);

	for (int i = 0; i < s.size(); i++)
	{
		save.push_back(s.at(i));
		arr.push_back(1);

		for (int j = 0; j < save.size() - 1; j++)
		{
			if (s.at(i) == save.at(j))
			{
				save.pop_back();
				arr.pop_back();
				arr.at(j)++;
			}
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (max < arr.at(i))
		{
			max = arr.at(i);
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr.at(i) == max)
		{
			num = i;
			stack++;
		}
	}

	if (stack > 1)
	{
		cout << "?";
	}
	else
	{
		cout << save.at(num);
	}

	return 0;
}