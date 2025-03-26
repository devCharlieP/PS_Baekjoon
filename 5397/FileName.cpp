#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#define endl "\n"
using namespace std;


void func()
{
	string s;
	cin >> s;

	list<char> L;

	auto pt = L.begin();

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '<')
		{
			if (pt != L.begin())
			{
				pt--;
			}			
		}
		else if (s[i] == '>')
		{
			if (pt != L.end())
			{
				pt++;
			}
		}
		else if (s[i] == '-')
		{
			if (pt != L.begin())
			{
				pt--;
				pt = L.erase(pt);
			}
		}
		else
		{
			L.insert(pt, s[i]);
		}
	}

	for (auto it = L.begin(); it != L.end(); it++)
	{
		cout << *it;
	}

	cout << endl;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		func();		
	}

	return 0;
}