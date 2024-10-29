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

	string s;
	cin >> s;

	stack<int> st;

	int res = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			if (s[i + 1] == ')')
			{
				i++;
				res += st.size();
			}
			else
			{
				st.push(1);
				res++;
			}
		}
		else
		{
			st.pop();
		}
	}

	cout << res;

	return 0;
}