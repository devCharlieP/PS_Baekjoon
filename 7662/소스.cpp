#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

vector <int> vec;

void input(int n)
{
	vec.push_back(n);
	sort(vec.begin(), vec.end());
}

void _delete(int n)
{
	if (!vec.empty())
	{
		if (n == 1)
		{
			vec.pop_back();
		}
		else
		{
			sort(vec.rbegin(), vec.rend());
			vec.pop_back();
			sort(vec.begin(), vec.end());
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int q = 1; q <= T; q++)
	{
		int	k;
		cin >> k;

		for (int w = 1; w <= k; w++)
		{
			char c;
			int n;

			cin >> c >> n;

			if (c == 'I')
			{
				input(n);
			}
			else if(c == 'D')
			{
				_delete(n);
			}
		}

		if (vec.empty())
		{
			cout << "EMPTY" << endl;
		}
		else
		{
			cout << vec[vec.size() - 1] << " " << vec[0] << endl;
		}
	}

	return 0;
}