#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int N = 0, cnt = 0;
vector <vector <int>> map(26, vector <int>(26));
vector <int> dx = {-1, 0, 1, 0};
vector <int> dy = {0, 1, 0, -1};

int dfs(int x, int y)
{
	int toX = 0, toY = 0;

	for (int i = 0; i < 4; i++)
	{
		toX = x + dx[i];
		toY = y + dy[i];

		if (toX >= 1 && toX <= N && toY >= 1 && toY <= N)
		{
			if (map[toX][toY] == 1)
			{
				map[toX][toY] = 0;
				cnt++;
				dfs(toX, toY);
			}
		}
	}

	return cnt;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	string s;

	for (int i = 1; i <= N; i++)
	{
		cin >> s;

		for (int j = 1; j <= N; j++)
		{
			map[i][j] = s[j - 1] - '0';
		}
	}

	vector <int> res;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 1)
			{
				map[i][j] = 0;
				cnt = 1;
				res.push_back(dfs(i, j));
			}
		}
	}

	sort(res.begin(), res.end());

	cout << res.size() << endl;

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}

	return 0;
}