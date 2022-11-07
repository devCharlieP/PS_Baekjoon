#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector <int> student(31);

	int num = 0;

	for (int i = 1; i <= 28; i++)
	{
		cin >> num;
		student[num] = 1;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (student[i] == 0)
		{
			cout << i << endl;
		}
	}

	return 0;
}