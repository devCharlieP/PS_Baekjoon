#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int R, C;

vector<vector<int>> map;
vector<vector<int>> ch;
vector<int> alphabet;

int res = -1;

vector<int> di = { -1, 1, 0, 0 };
vector<int> dj = { 0, 0, -1, 1 };

void dfs(int cur_i, int cur_j, int depth)
{
	res = max(res, depth);

	for (int i = 0; i < 4; i++)
	{
		int dest_i = cur_i + di[i];
		int dest_j = cur_j + dj[i];

		if (dest_i < 0 || dest_i >= R || dest_j < 0 || dest_j >= C || ch[dest_i][dest_j] == 1 || alphabet[map[dest_i][dest_j] - 'A'] == 1)
		{
			continue;
		}

		ch[dest_i][dest_j] = 1;
		alphabet[map[dest_i][dest_j] - 'A'] = 1;

		dfs(dest_i, dest_j, depth + 1);

		ch[dest_i][dest_j] = 0;
		alphabet[map[dest_i][dest_j] - 'A'] = 0;
	}		
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;

	map = vector<vector<int>>(R, vector<int>(C));
	ch = vector<vector<int>>(R, vector<int>(C));
	alphabet = vector<int>(26);

	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < C; j++)
		{
			map[i][j] = s[j];
		}
	}

	ch[0][0] = 1;
	alphabet[map[0][0] - 'A'] = 1;

	dfs(0, 0, 1);

	cout << res;

	return 0;
}