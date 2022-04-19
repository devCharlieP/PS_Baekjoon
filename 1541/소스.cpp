#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	int ptr_s = 0;
	int ptr_e = 1;
	int sum = 0;
	bool b = false;

	for (int i = 0; i < s.size(); i++)
	{
		if (i + 1 == s.size() || s[i + 1] == '+' || s[i + 1] == '-')
		{
			string num = s.substr(ptr_s, ptr_e);

			if (b == false)
			{
				sum += stoi(num);
			}
			else
			{
				sum -= stoi(num);
			}

			if (s[i + 1] == '-')
			{
				b = true;
			}

			ptr_s = i + 2;
			ptr_e = -1;
		}

		ptr_e++;
	}

	cout << sum;

	return 0;
}