#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

void bfs()
{
	int l;
	cin >> l;

	pair<int, int> start;
	cin >> start.first >> start.second;

	pair<int, int> finish;
	cin >> finish.first >> finish.second;

	vector<int> di = { -1, -2, -2, -1, 1, 2, 2, 1 };
	vector<int> dj = { -2, -1, 1, 2, 2, 1, -1, -2 };

	vector<vector<int>> ch(l, vector<int>(l, -1));

	queue<pair<int, int>> q;
	q.push(start);
	ch[start.first][start.second] = 0;
	
	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();

		for (int i = 0; i < di.size(); i++)
		{
			int tempi = di[i] + front.first;
			int tempj = dj[i] + front.second;

			if(0 <= tempi && tempi < l && 0 <= tempj && tempj < l && ch[tempi][tempj] == -1)
			{ 
				ch[tempi][tempj] = ch[front.first][front.second] + 1;
				q.push(make_pair(tempi, tempj));
			}
		}
	}

	cout << ch[finish.first][finish.second] << endl;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		bfs();
	}

	return 0;
}