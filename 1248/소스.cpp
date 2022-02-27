#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int N;
vector <vector<char>> op(30, vector<char>(30, -1));
vector <int> vec(11);

void dfs(int x, int y, int L, int cnt)
{
	if (cnt == (N * (N + 1)) / 2)
	{
		for (int i = 1; i <= N; i++)
		{
			cout << vec[i] << " ";
		}

		exit(0);
	}
	if (op[x][y] == '+')
	{
		if (L > 0)
		{
			if (y == N)
			{
				for (int i = -10; i <= 10; i++)
				{
					dfs(x - 1, x - 1, i, cnt + 1);
				}
				
			}
			else if(x == y)
			{
				vec[x] = L;
				dfs(x, y + 1, L + vec[y + 1], cnt + 1);
			}
			else
			{
				dfs(x, y + 1, L + vec[y + 1], cnt + 1);
			}
		}
		else
		{
			return;
		}
	}
	else if (op[x][y] == '-')
	{
		if (L < 0)
		{
			if (y == N)
			{
				for (int i = -10; i <= 10; i++)
				{
					dfs(x - 1, x - 1, i, cnt + 1);
				}

			}
			else if(x == y)
			{
				vec[x] = L;
				dfs(x, y + 1, L + vec[y + 1], cnt + 1);
			}
			else
			{
				dfs(x, y + 1, L + vec[y + 1], cnt + 1);
			}
		}
		else
		{
			return;
		}
	}
	else if(op[x][y] == '0')
	{
		if (L == 0)
		{
			if (y == N)
			{
				for (int i = -10; i <= 10; i++)
				{
					dfs(x - 1, x - 1, i, cnt + 1);
				}

			}
			else if(x == y)
			{
				vec[x] = L;
				dfs(x, y + 1, L + vec[y + 1], cnt + 1);
			}
			else
			{
				dfs(x, y + 1, L + vec[y + 1], cnt + 1);
			}
		}
		else
		{
			return;
		}
	}


}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			cin >> op[i][j];
		}
	}

	for (int i = -10; i <= 10; i++)
	{
		vec[N] = i;
		dfs(N, N, i, 0);
	}
	
	return 0;
}