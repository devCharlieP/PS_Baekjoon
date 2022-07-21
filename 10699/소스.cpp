#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	time_t t = time(NULL);
	struct tm* now = localtime(&t);

	int year = now->tm_year + 1900;
	int mon = now->tm_mon + 1;
	int day = now->tm_mday;

	if (mon < 10)
	{
		if (day < 10)
		{
			cout << year << "-0" << mon << "-0" << day << endl;
		}
		else
		{
			cout << year << "-0" << mon << "-" << day << endl;
		}
	}
	else
	{
		if (day < 10)
		{
			cout << year << "-" << mon << "-0" << day << endl;
		}
	}

	return 0;
}