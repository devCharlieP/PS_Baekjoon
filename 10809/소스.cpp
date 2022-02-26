#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	string a = "abcdefghijklmnopqrstuvwxyz";

	cin >> s;

	for (int i = 0; i < a.size(); i++)
	{
		int save = 0;

		for (int j = 0; j < s.size(); j++)
		{
			if (s.at(j) == a.at(i))
			{
				cout << j << " ";
				save = j;
				break;
			}
		}
		
		if (s.at(save) != a.at(i))
		{
			cout << "-1" << " ";
		}
	}

	return 0;
}