#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector <int> vec(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	vector <char> vec_c;
	stack <int> s;

	bool b = true;
	int j = 1;

	for (int i = 1; i <= n;)
	{
		if (s.empty() || s.top() != vec[i])
		{
			if (j > n)
			{
				b = false;
				break;
			}

			vec_c.push_back('+');
			s.push(j);
			j++;
		}
		else
		{
			vec_c.push_back('-');
			i++;
			s.pop();
		}
	}

	if (b == true)
	{
		for (int i = 0; i < vec_c.size(); i++)
		{
			cout << vec_c[i] << endl;
		}
	}
	else
	{
		cout << "NO";
	}

	return 0;
}