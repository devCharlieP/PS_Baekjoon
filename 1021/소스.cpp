#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	deque<int> dq;
	
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	vector<int> vec(M);

	for (int i = 0; i < M; i++)
	{
		cin >> vec[i];
	}

	int res = 0;

	for (int i = 0; i < M; i++)
	{
		int cnt1 = 0, cnt2 = 0;
		deque<int> dq1, dq2;

		dq1 = dq;

		while (1)
		{
			if (dq1.front() == vec[i])
			{
				dq1.pop_front();
				break;
			}
			else
			{
				int front = dq1.front();
				dq1.pop_front();
				dq1.push_back(front);

				cnt1++;
			}
		}

		dq2 = dq;

		while (1)
		{
			if (dq2.front() == vec[i])
			{
				dq2.pop_front();
				break;
			}
			else
			{
				int back = dq2.back();
				dq2.pop_back();
				dq2.push_front(back);

				cnt2++;
			}
		}

		if (cnt1 < cnt2)
		{
			res += cnt1;
			dq = dq1;
		}
		else
		{
			res += cnt2;
			dq = dq2;
		}
	}

	cout << res;

	return 0;
}