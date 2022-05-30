#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

int N;
vector <vector <int>> map(101, vector<int>(101));
vector <vector <int>> res(101, vector<int>(101));

void bfs(int left)
{
	vector <int> ch(101);
	ch[left] = 1;

	queue <int> Q;
	Q.push(left);

	int level = 0;

	while (!Q.empty())
	{
		level = Q.front();
		Q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (map[level][i] == 1)
			{
				if (ch[i] == 1)
				{
					res[left][i] = 1;
				}
				else
				{
					Q.push(i);
					res[left][i] = 1;
					ch[i] = 1;
				}
			}
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
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		bfs(i);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << res[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}