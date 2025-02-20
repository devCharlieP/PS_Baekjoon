#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

vector<int> di = { -1, 1, 0, 0 };
vector<int> dj = { 0, 0, -1, 1 };

int n, m;
vector<vector<int>> map;
vector<vector<int>> ch;

int res_cnt = 0;
int res_size = 0;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	map = vector<vector<int>>(n, vector<int>(m));
	ch = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1 && ch[i][j] == 0)
			{
				res_cnt++;

				q.push({ i, j });
				ch[i][j] = 1;

				int size = 1;

				while (!q.empty())
				{
					pair<int, int> front = q.front();

					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int dest_i = front.first + di[i];
						int dest_j = front.second + dj[i];

						if (0 <= dest_i && dest_i < n && 0 <= dest_j && dest_j < m &&
							map[dest_i][dest_j] == 1 && ch[dest_i][dest_j] == 0)
						{
							ch[dest_i][dest_j] = 1;
							size++;
							q.push({ dest_i, dest_j });
						}
					}
				}

				res_size = max(res_size, size);
			}			
		}
	}

	cout << res_cnt << endl << res_size;

	return 0;
}