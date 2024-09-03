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

	int N;
	cin >> N;

	vector<int> tower(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> tower[i];
	}

	stack<pair<int, int>> s;
	vector<int> res;

	for (int i = 1; i <= N; i++)
	{
		while (!s.empty())
		{
			if (s.top().second > tower[i])
			{
				res.push_back(s.top().first);
				break;
			}

			s.pop();
		}

		if (s.empty())
		{
			res.push_back(0);
		}

		s.push(make_pair(i, tower[i]));
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}		

	return 0;
}