#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;
#define endl "\n"

int main()
{
	while (1)
	{
		string s;
		getline(cin, s);

		if (s == ".")
		{
			break;
		}

		stack <char> ch;
		bool b = true;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[')
			{
				ch.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == ']')
			{
				if (ch.empty())
				{
					b = false;
					break;
				}
			
				if (s[i] == ')')
				{
					if (ch.top() == '(')
					{
						ch.pop();
					}
					else
					{
						b = false;
						break;
					}
				}
				else
				{
					if (ch.top() == '[')
					{
						ch.pop();
					}
					else
					{
						b = false;
						break;
					}
				}
			}
		}

		if (!ch.empty())
		{
			b = false;
		}

		if (b == true)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}

	return 0;
}