#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	int r = 0;
	int cnt = 1;

	vector<int> res;

	while (!q.empty())
	{
		r = q.front();

		q.pop();

		if (cnt != K)
		{
			cnt++;
			q.push(r);
		}
		else
		{
			cnt = 1;
			res.push_back(r);
		}
	}

	for (int i = 0; i < res.size(); i++)
	{
		if (i == 0 && i == res.size() - 1)
		{
			cout << "<" << res[i] << ">";
		}
		else if (i == 0)
		{
			cout << "<" << res[i] << ", ";
		}
		else if (i == res.size() - 1)
		{
			cout << res[i] << ">";
		}
		else
		{
			cout << res[i] << ", ";
		}
	}

	return 0;
}