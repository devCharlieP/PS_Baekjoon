#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	if (s[0] == 'A')
	{
		if (s[1] == '+')
			cout << "4.3";
		else if (s[1] == '0')
			cout << "4.0";
		else
			cout << "3.7";
	}
	else if (s[0] == 'B')
	{
		if (s[1] == '+')
			cout << "3.3";
		else if (s[1] == '0')
			cout << "3.0";
		else
			cout << "2.7";
	}
	else if (s[0] == 'C')
	{
		if (s[1] == '+')
			cout << "2.3";
		else if (s[1] == '0')
			cout << "2.0";
		else
			cout << "1.7";
	}
	else if (s[0] == 'D')
	{
		if (s[1] == '+')
			cout << "1.3";
		else if (s[1] == '0')
			cout << "1.0";
		else
			cout << "0.7";
	}
	else
		cout << "0.0";

	return 0;
}