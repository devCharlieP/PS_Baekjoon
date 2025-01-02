#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define endl "\n"
using namespace std;

vector<deque<int>> wheels(5);

void turn(int n, int d)
{
	if (d == -1)
	{
		int temp = wheels[n].front();
		wheels[n].pop_front();
		wheels[n].push_back(temp);
	}
	else
	{
		int temp = wheels[n].back();
		wheels[n].pop_back();
		wheels[n].push_front(temp);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	for (int i = 1; i <= 4; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < 8; j++)
		{
			wheels[i].push_back(s[j] - '0');
		}
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int n, d;
		cin >> n >> d;

		if (n == 1)
		{
			if (wheels[1][2] != wheels[2][6])
			{
				if (wheels[2][2] != wheels[3][6])
				{
					if (wheels[3][2] != wheels[4][6])
					{
						turn(4, -d);
					}

					turn(3, d);
				}

				turn(2, -d);
			}

			turn(1, d);
		}
		else if (n == 2)
		{
			if (wheels[2][6] != wheels[1][2])
			{
				turn(1, -d);
			}

			if (wheels[2][2] != wheels[3][6])
			{
				if (wheels[3][2] != wheels[4][6])
				{
					turn(4, d);
				}

				turn(3, -d);
			}

			turn(2, d);
		}
		else if (n == 3)
		{
			if (wheels[3][2] != wheels[4][6])
			{
				turn(4, -d);
			}

			if (wheels[3][6] != wheels[2][2])
			{
				if (wheels[2][6] != wheels[1][2])
				{
					turn(1, d);
				}

				turn(2, -d);
			}

			turn(3, d);
		}
		else
		{
			if (wheels[4][6] != wheels[3][2])
			{
				if (wheels[3][6] != wheels[2][2])
				{
					if (wheels[2][6] != wheels[1][2])
					{
						turn(1, -d);
					}

					turn(2, d);
				}

				turn(3, -d);
			}

			turn(4, d);
		}
	}

	int temp = 1;
	int res = 0;

	for (int i = 1; i <= 4; i++)
	{
		if (wheels[i].front() == 1)
		{
			res += temp;
		}

		temp *= 2;
	}

	cout << res;

	return 0;
}