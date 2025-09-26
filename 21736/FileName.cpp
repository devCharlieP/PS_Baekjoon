#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int N, M;
int result = 0;
vector<vector<char>> map;
vector<vector<int>> ch;

vector<int> di = { 1, -1, 0 ,0 };
vector<int> dj = { 0, 0, -1, 1 };

void dfs(int cur_i, int cur_j)
{
	for (int i = 0; i < 4; i++)
	{
		int dest_i = cur_i + di[i];
		int dest_j = cur_j + dj[i];

		if (dest_i >= 0 && dest_i < N && dest_j >= 0 && dest_j < M && map[dest_i][dest_j] != 'X' && ch[dest_i][dest_j] == 0)
		{
			if (map[dest_i][dest_j] == 'P')
			{
				result++;
			}

			ch[dest_i][dest_j] = 1;
			dfs(dest_i, dest_j);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	map = vector<vector<char>>(N, vector<char>(M));
	ch = vector<vector<int>>(N, vector<int>(M));

	int cur_i = 0;
	int cur_j = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'I')
			{
				cur_i = i;
				cur_j = j;
			}
		}
	}

	ch[cur_i][cur_j] = 1;
	dfs(cur_i, cur_j);

	if (result == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << result;
	}	

	return 0;
}