#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> dx = {0, 0, 1, -1};
vector <int> dy = {1, -1, 0, 0};

int n, m;
int maxi = -987654321;

vector <vector<int>> vec(501, vector<int>(501));
vector <vector<int>> ch(501, vector<int>(501));

int save_i, save_j;

void dfs(int i, int j, int len, int sum)
{
	if (len == 4)
	{
		if (sum > maxi)
		{
			maxi = sum;
		}

		return;
	}
	else
	{
		for (int k = 0; k < 4; k++)
		{
			if (ch[i][j] == 0 
				&& 0 <= i + dy[k] && i + dy[k] < n 
				&& 0 <= j + dx[k] && j + dx[k] < m)
			{
				ch[i][j] = 1;
				dfs(i + dy[k], j + dx[k], len + 1, sum + vec[i][j]);
				ch[i][j] = 0;
			}
		}
	}
}

void dfs_2(int i, int j, int len, int sum)
{
	if (len == 3)
	{
		for (int k = 0; k < 4; k++)
		{
			if (0 <= save_i + dy[k] && save_i + dy[k] < n
				&& 0 <= save_j + dx[k] && save_j + dx[k] < m 
				&& ch[save_i + dy[k]][save_j + dx[k]] == 0)
			{
				sum += vec[save_i + dy[k]][save_j + dx[k]];

				if (sum > maxi)
				{
					maxi = sum;
				}

				sum -= vec[save_i + dy[k]][save_j + dx[k]];
			}
		}
		
		return;
	}
	else
	{
		for (int k = 0; k < 4; k++)
		{
			if (ch[i][j] == 0
				&& 0 <= i + dy[k] && i + dy[k] < n
				&& 0 <= j + dx[k] && j + dx[k] < m)
			{
				ch[i][j] = 1;

				if (len == 1)
				{
					save_i = i;
					save_j = j;
				}
			
				dfs_2(i + dy[k], j + dx[k], len + 1, sum + vec[i][j]);
			
				ch[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> vec[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dfs(i, j, 0, 0);
			dfs_2(i, j, 0, 0);
		}
	}

	cout << maxi;

	return 0;
}