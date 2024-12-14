#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	string bomb;
	cin >> bomb;

	string temp;

	for (int i = 0; i < s.size(); i++)
	{
		temp.push_back(s[i]);

		if (temp.size() >= bomb.size() && temp.substr(temp.size() - bomb.size()) == bomb)
		{
			for (int j = 0; j < bomb.size(); j++)
			{
				temp.pop_back();
			}
		}
	}

	if (!temp.empty())
	{
		cout << temp;
	}
	else
	{
		cout << "FRULA";
	}

	return 0;
}