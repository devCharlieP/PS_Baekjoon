#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

int N;
vector <int> res(100001);
vector <int> tree[100001];
vector <int> ch(100001);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 1; i <= N - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	queue <int> Q;
	Q.push(1);

	while (!Q.empty())
	{
		int front = Q.front();
		Q.pop();
		
		ch[front] = 1;

		for (int i = 0; i < tree[front].size(); i++)
		{
			int tree_Front = tree[front][i];

			if (ch[tree_Front] == 0)
			{
				ch[tree_Front] = 1;
				res[tree_Front] = front;
				Q.push(tree_Front);
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << res[i] << endl;
	}

	return 0;
}