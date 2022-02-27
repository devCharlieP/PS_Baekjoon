#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n = 0;
int cnt_max = -987654321;
vector <vector<char>> candy(51, vector<char>(51));


void count(int k, int l)
{
	int cnt = 1;

	while(1)
	{
		if (candy[k][l] == candy[k][l + 1] && l + 1 < n)
		{
			cnt++;
			l++;
		}
		else
		{
			break;
		}
	}

	if (cnt_max < cnt)
	{
		cnt_max = cnt;
	}

	cnt = 1;

	while (1)
	{
		if (candy[k][l] == candy[k + 1][l] && k + 1 < n)
		{
			cnt++;
			k++;
		}
		else
		{
			break;
		}
	}
	
	if (cnt_max < cnt)
	{
		cnt_max = cnt;
	}

}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			candy[i][j] = c;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < n - 1 && candy[i][j] != candy[i + 1][j])
			{
				swap(candy[i][j], candy[i + 1][j]);

				for (int k = 0; k < n; k++)
				{
					for (int l = 0; l < n; l++)
					{
						count(k, l);
					}
				}

				swap(candy[i][j], candy[i + 1][j]);
			}
			if (j < n - 1 && candy[i][j] != candy[i][j + 1])
			{
				swap(candy[i][j], candy[i][j + 1]);

				for (int k = 0; k < n; k++)
				{
					for (int l = 0; l < n; l++)
					{
						count(k, l);
					}
				}

				swap(candy[i][j], candy[i][j + 1]);
			}
		}
	}

	cout << cnt_max;

	return 0;
}