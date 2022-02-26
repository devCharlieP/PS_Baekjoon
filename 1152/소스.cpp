#include <iostream>
#include <string>
using namespace std;

int main()
{
	int cnt = 0;
	string s;
	getline(cin, s);
	s.push_back(' ');

	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s.at(i) != ' ' && s.at(i + 1) == ' ')
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}