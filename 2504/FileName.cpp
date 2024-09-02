#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	stack <char> brs;

	int res = 0, temp = 1;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			temp *= 2;
			brs.push('(');
		}
		else if (str[i] == '[')
		{
			temp *= 3;
			brs.push('[');
		}
		else if (str[i] == ')')
		{
			if (brs.empty() || brs.top() != '(')
			{
				res = 0;
				break;
			}

			if (str[i - 1] == '(')
			{
				res += temp;
			}

			temp /= 2;
			brs.pop();
		}
		else
		{
			if (brs.empty() || brs.top() != '[')
			{
				res = 0;
				break;
			}

			if (str[i - 1] == '[')
			{
				res += temp;
			}

			temp /= 3;
			brs.pop();
		}
	}

	if (!brs.empty())
	{
		res = 0;
	}

	cout << res;

	return 0;
}