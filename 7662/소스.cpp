#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#define endl '\n'
using namespace std;

priority_queue<int> max_Q;
priority_queue<int, vector<int>, greater<int>> min_Q;
map<int, int> M;

void input(int n)
{
	max_Q.push(n);
	min_Q.push(n);

	M[n]++;
}

void del(int n)
{	
	int top = 0;

	if (n == 1)
	{
		if (max_Q.empty())
		{
			return;
		}

		top = max_Q.top();
	}
	else
	{
		if (min_Q.empty())
		{
			return;
		}

		top = min_Q.top();
	}

	M[top]--;
	if (M[top] < 0)
	{
		M[top] = 0;
	}

	top = max_Q.top();

	while (M[top] == 0)
	{
		max_Q.pop();

		if (max_Q.empty())
		{
			break;
		}

		top = max_Q.top();
	}

	top = min_Q.top();

	while (M[top] == 0)
	{
		min_Q.pop();

		if(min_Q.empty())
		{
			break;
		}

		top = min_Q.top();
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int z = 1; z <= T; z++)
	{
		max_Q = priority_queue <int>();
		min_Q = priority_queue <int, vector <int>, greater<int>>();
		M = map <int, int>();

		int k;
		cin >> k;

		char c;
		int n;

		for (int y = 1; y <= k; y++)
		{
			cin >> c >> n;

			if (c == 'I')
			{
				input(n);
			}
			else
			{
				del(n);
			}
		}

		if (max_Q.empty() && min_Q.empty())
		{
			cout << "EMPTY" << endl;
		}
		else if (max_Q.empty())
		{
			cout << min_Q.top() << " " << min_Q.top() << endl;
		}
		else if (min_Q.empty())
		{
			cout << max_Q.top() << " " << max_Q.top() << endl;
		}
		else
		{
			cout << max_Q.top() << " " << min_Q.top() << endl;
		}
	}

	return 0;
}