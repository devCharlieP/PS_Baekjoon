#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	string s, temp;

	for (int i = 1; i <= 8; i++)
	{
		cin >> n;
		temp = s;

		if (n == i)
		{
			s = "ascending";
		}
		else if (n == 9 - i)
		{
			s = "descending";
		}
		else
		{
			s = "mixed";
			break;
		}

		if (temp != "" && s != temp)
		{
			s = "mixed";
			break;
		}
	}

	cout << s;

	return 0;
}