#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl "\n"
using namespace std;

int N;
int cnt = 0;
vector <int> vec(15);

void dfs(int dfs_cnt)
{
	if (dfs_cnt == N + 1)
	{
		cnt++;
		return;
	}

	vector <int> ch(N + 1, 1);

	for (int i = 1; i <= dfs_cnt - 1; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (vec[i] != 0)
			{
				if (vec[i] == j || abs(i - dfs_cnt) == abs(vec[i] - j))
				{
					ch[j] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (ch[i] == 1)
		{
			vec[dfs_cnt] = i;
			dfs(dfs_cnt + 1);
		}
	}
	
	return;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int j = 1; j <= N; j++)
	{
		vec[1] = j;
		dfs(2);
	}

	cout << cnt;

	return 0;
}