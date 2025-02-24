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

	string s;
	getline(cin, s);

	string temp;
	bool b = true;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '<')
		{
			b = false;

			if (!temp.empty())
			{
				for (int j = temp.size() - 1; j >= 0; j--)
				{
					cout << temp[j];
				}

				temp.clear();
			}			
		}
		else if (s[i] == '>')
		{
			b = true;
			cout << s[i];

			continue;
		}
		else if (s[i] == ' ' && b)
		{
			if (!temp.empty())
			{
				for (int j = temp.size() - 1; j >= 0; j--)
				{
					cout << temp[j];
				}

				cout << " ";

				temp.clear();
			}
			
			continue;
		}

		if (b)
		{
			temp.push_back(s[i]);
		}
		else
		{
			cout << s[i];
		}
	}

	if (!temp.empty())
	{
		for (int j = temp.size() - 1; j >= 0; j--)
		{
			cout << temp[j];
		}
	}

	return 0;
}