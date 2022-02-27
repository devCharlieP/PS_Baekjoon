#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <vector<int>> vec(21, vector<int>(21));
vector<int> ch(21);
int mini = 987654321;

void dfs(int idx, int cnt)
{
	if (cnt == (n / 2) - 1)
	{
		int sum_team1 = 0;
		int sum_team0 = 0;

		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (ch[i] == ch[j] && ch[i] == 1)
				{
					sum_team1 += vec[i][j];
					sum_team1 += vec[j][i];
				}
				else if (ch[i] == ch[j] && ch[i] == 0)
				{
					sum_team0 += vec[i][j];
					sum_team0 += vec[j][i];
				}
			}
		}

		if (mini > abs(sum_team1 - sum_team0))
		{
			mini = abs(sum_team1 - sum_team0);
		}
	}
	else
	{
		for (int i = idx; i <= n; i++)
		{
			if (ch[i] == 0)
			{
				ch[i] = 1;
				dfs(i + 1, cnt + 1);
				ch[i] = 0;
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> vec[i][j];
		}
	}

	ch[1] = 1;

	dfs(2, 0);

	cout << mini;

	return 0;
}