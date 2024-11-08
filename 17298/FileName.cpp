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

	vector<int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	vector<int> res(N, - 1);

	stack<pair<int,int>> s;

	for (int i = 0; i < N; i++)
	{
		if (s.empty() || s.top().first >= vec[i])
		{
			s.push({ vec[i], i });
		}
		else
		{
			while (s.top().first < vec[i])
			{
				res[s.top().second] = vec[i];
				s.pop();

				if (s.empty())
					break;
			}

			s.push({ vec[i], i });
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << res[i] << " ";
	}

	return 0;
}