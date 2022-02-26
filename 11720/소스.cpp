#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a;
	int b;
	int sum = 0;
	string str;

	cin >> a;
	cin >> str;

	for (int i = 0; i < a; i++)
	{
		sum += str.at(i) - '0';
	}
	
	cout << sum << endl;

	return 0;
}