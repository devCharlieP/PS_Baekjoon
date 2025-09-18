#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int res = 0;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		stack<char> s;

		for (int j = 0; j < str.size(); j++)
		{
			if (s.empty())
			{
				s.push(str[j]);
			}
			else
			{
				if (s.top() == str[j])
				{
					s.pop();
				}
				else
				{
					s.push(str[j]);
				}
			}
		}

		if (s.empty())
		{
			res++;
		}
	}

	cout << res;

	return 0;
}