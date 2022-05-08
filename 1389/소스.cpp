#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define endl "\n"

int N;
vector <vector <int>> vec(101, vector <int>(101));

int bfs(int user)
{
	int tempUser = 0;

	vector<int> ch(101);
	vector<int> num(101);

	queue <int> Q;
	Q.push(user);
	ch[user] = 1;
	num[user] = 0;

	while (!Q.empty())
	{
		tempUser = Q.front();
		Q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (vec[tempUser][i] == 1 && ch[i] == 0)
			{
				ch[i] = 1;
				num[i] = num[tempUser] + 1;
				Q.push(i);
			}
		}
	}

	int sum = 0;

	for (int i = 1; i <= N; i++)
	{
		sum += num[i];
	}

	return sum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M;
	cin >> N >> M;

	int x, y;

	for (int i = 1; i <= M; i++)
	{
		cin >> x >> y;
		
		vec[x][y] = 1;
		vec[y][x] = 1;
	}

	int numKevin = 0;
	int min = 987654321;
	int res = 0;

	for (int i = 1; i <= N; i++)
	{
		numKevin = bfs(i);

		if (numKevin < min)
		{
			min = numKevin;
			res = i;
		}
	}

	cout << res;

	return 0;
}