#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num;
	cin >> num;

	string *arr = new string [num];

	int sum = 0;
	int score = 0;

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < num; i++)
	{
		sum = 0;
		score = 0;

		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i].at(j) == 'O')
			{
				score++;
				sum += score;
			}
			else
			{
				score = 0;
			}
		}
		cout << sum << endl;
	}

	return 0;
}