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

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	vector<int> ch(100001);

	pq.push({ 0, N });

	int res = 0;

	while (!pq.empty())
	{
		int cur_time = pq.top().first;
		int cur_X = pq.top().second;

		pq.pop();

		ch[cur_X] = 1;

		if (cur_X == K)
		{
			res = cur_time;
			break;
		}

		if (cur_X >= 1 && ch[cur_X - 1] == 0)
		{
			pq.push({ cur_time + 1, cur_X - 1 });
		}

		if (cur_X <= 99999 && ch[cur_X + 1] == 0)
		{
			pq.push({ cur_time + 1, cur_X + 1 });
		}
			
		if (cur_X <= 50000 && ch[cur_X * 2] == 0)
		{
			pq.push({ cur_time, cur_X * 2 });
		}
	}

	cout << res;

	return 0;
}