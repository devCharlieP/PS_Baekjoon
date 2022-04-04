#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

vector <vector<int>> vec(129, vector<int>(129));
int cnt_white = 0, cnt_blue = 0;

void rec(int N, int k, int l)
{
	int temp = vec[k][l];

	if (N == 1)
	{
		if (temp == 0)
		{
			cnt_white++;
		}
		else
		{
			cnt_blue++;
		}

		return;
	}
	else
	{
		bool b = true;

		for (int i = k; i <= k + N - 1; i++)
		{
			for (int j = l; j <= l + N - 1; j++)
			{
				if (temp != vec[i][j])
				{
					b = false;
					break;
				}
			}

			if (b == false)
			{
				break;
			}
		}

		if (b == false)
		{
			rec(N / 2, k, l);
			rec(N / 2, k, l + N / 2);
			rec(N / 2, k + N / 2, l);
			rec(N / 2, k + N / 2, l + N / 2);
		}
		else
		{
			if (temp == 0)
			{
				cnt_white++;
			}
			else
			{
				cnt_blue++;
			}

			return;
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> vec[i][j];
		}
	}

	rec(N, 1, 1);

	cout << cnt_white << endl << cnt_blue;

	return 0;
}