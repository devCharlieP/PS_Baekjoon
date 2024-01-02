#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> deque(2000001);
	int head = deque.size() / 2;
	int tail = deque.size() / 2;
	int d_size = 0;

	for (int i = 1; i <= N; i++)
	{
		int order;
		cin >> order;

		int x;
		if (order == 1)
		{
			cin >> x;
			deque[--head] = x;
			d_size++;
		}
		else if (order == 2)
		{
			cin >> x;
			deque[tail++] = x;
			d_size++;
		}
		else if (order == 3)
		{
			if (d_size != 0)
			{
				cout << deque[head] << endl;
				deque[head] = 0;
				head++;
				d_size--;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (order == 4)
		{
			if (d_size != 0)
			{
				cout << deque[tail - 1] << endl;
				deque[tail - 1] = 0;
				tail--;
				d_size--;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (order == 5)
		{
			cout << d_size << endl;
		}
		else if (order == 6)
		{
			if (d_size == 0)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (order == 7)
		{
			if (d_size != 0)
			{
				cout << deque[head] << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (order == 8)
		{
			if (d_size != 0)
			{
				cout << deque[tail - 1] << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}

	}

	return 0;
}