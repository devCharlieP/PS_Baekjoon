#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num = 0;
	string s;
	cin >> s;

	int array[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
	
	for (int i = 0; i < s.size(); i++)
	{
		num += array[s.at(i) - 'A'];
	}

	num += s.size();

	cout << num;

	return 0;
}