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

	vector<int> queue(2000001);

	int N;
	cin >> N;

	string s;
	int left = 0;
	int right = 0;

	for (int i = 1; i <= N; i++)
	{
		cin >> s;

		if (s == "push")
		{
			cin >> queue[right];
			right++;
		}
		else if (s == "pop")
		{
			if (right - left == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << queue[left] << endl;

				left++;
			}
		}
		else if (s == "size")
		{
			cout << right - left << endl;

		}
		else if (s == "empty")
		{
			if (right - left == 0)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (s == "front")
		{
			if (right - left == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << queue[left] << endl;
			}
		}
		else
		{
			if (right - left == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << queue[right - 1] << endl;
			}
		}
	}

	return 0;
}