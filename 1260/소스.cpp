#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"
using namespace std;

int N, M, V;

vector <vector <int>> vec(1001, vector <int>(1001));
vector <int> dfs_ch(1001);

void dfs(int p)
{
	for (int i = 1; i <= N; i++)
	{
		if (vec[p][i] == 1 && dfs_ch[i] == 0)
		{
			cout << i << " ";
			dfs_ch[i] = 1;
			dfs(i);
		}
	}
}

queue<int> Q;
vector <int> bfs_ch(1001);

void bfs(int p)
{
	int front = 0;

	bfs_ch[p] = 1;
	Q.push(p);

	while (!Q.empty())
	{
		front = Q.front();
		cout << front << " ";

		Q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (vec[front][i] == 1 && bfs_ch[i] == 0)
			{
				bfs_ch[i] = 1;
				Q.push(i);
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++)
	{
		int x, y;
		cin >> x >> y;

		vec[x][y] = 1;
		vec[y][x] = 1;
	}

	dfs_ch[V] = 1;
	cout << V << " ";
	dfs(V);
	cout << endl;
	
	bfs(V);

	return 0;
}