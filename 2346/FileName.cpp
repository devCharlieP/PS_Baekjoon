#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vec(N + 1);
	deque<int> dq;

	for (int i = 1; i <= N; i++)
	{
		cin >> vec[i];
		dq.push_back(i);
	}

	bool b = true;

	while (1)
	{
		int tf = 0;

		if (b)
		{
			cout << dq.front() << " ";

			tf = vec[dq.front()];
			dq.pop_front();
		}
		else
		{
			cout << dq.back() << " ";

			tf = vec[dq.back()];
			dq.pop_back();
		}

		if (dq.size() == 0)
			break;

		if (tf > 0)
		{
			for (int i = 1; i < tf; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}

			b = true;
		}
		else
		{
			for (int i = -1; i > tf; i--)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}

			b = false;
		}
	}

	return 0;
}