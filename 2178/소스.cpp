#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl "\n"

int N, M;
vector <vector <int>> miro(101, vector <int>(101));
vector <vector <int>> miroMin(101, vector<int>(101, 10001));
vector <vector <int>> ch(101, vector <int>(101));
vector <int> dx {-1, 0, 1, 0};
vector <int> dy {0, 1, 0, -1};

void dfs(int x, int y)
{
	if (x == N && y == M)
	{
		return;
	}

	int toX = 0, toY = 0;

	for (int i = 0; i < 4; i++)
	{
		toX = x + dx[i];
		toY = y + dy[i];

		if (toX >= 1 && toX <= N && toY >= 1 && toY <= M)
		{
			if (miro[toX][toY] == 1 && ch[toX][toY] == 0 && miroMin[x][y] + 1 < miroMin[toX][toY])
			{
				ch[toX][toY] = 1;
				miroMin[toX][toY] = miroMin[x][y] + 1;
				dfs(toX, toY);
				ch[toX][toY] = 0;
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	string s;

	for (int i = 1; i <= N; i++)
	{
		cin >> s;

		for (int j = 1; j <= M; j++)
		{
			miro[i][j] = s[j - 1] - '0';
		}
	}

	ch[1][1] = 1;
	miroMin[1][1] = 1;

	dfs(1, 1);

	cout << miroMin[N][M];

	return 0;
}