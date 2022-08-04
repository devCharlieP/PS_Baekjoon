#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

priority_queue<int> max_Q;
priority_queue<int, vector<int>, greater<int>> min_Q;
vector <long long> vec;

void input(int n)
{
	max_Q.push(n);
	min_Q.push(n);
}

void _delete(int n)
{
	int d = 0;

	if (n == 1)
	{
		d = max_Q.top();

		while (!max_Q.empty() && vec[d] == 0)
		{
			max_Q.pop();
		}

		vec[d]--;

		max_Q.pop();
	}
	else if(n == -1)
	{
		d = min_Q.top();
		vec[d]--;

		min_Q.pop();
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
				vec[n]++;
			}
			else if(c == 'D')
			{
				_delete(n);
			}
		}		
	}

	return 0;
}