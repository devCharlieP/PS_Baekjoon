#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b, c;
	cin >> a >> b >> c;

	int res;

	if (a != "FizzBuzz" && a != "Fizz" && a != "Buzz")
	{
		res = stoi(a) + 3;
	}
	else if (b != "FizzBuzz" && b != "Fizz" && b != "Buzz")
	{
		res = stoi(b) + 2;
	}
	else
	{
		res = stoi(c) + 1;
	}

	if (res % 3 == 0 && res % 5 == 0)
	{
		cout << "FizzBuzz";
	}
	else if (res % 3 == 0)
	{
		cout << "Fizz";
	}
	else if (res % 5 == 0)
	{
		cout << "Buzz";
	}
	else
	{
		cout << res;
	}

	return 0;
}