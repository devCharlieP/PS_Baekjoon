#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl "\n"
using namespace std;

int N, M;
vector <vector<int>> vec(5, vector <int>(5));
vector <vector<int>> ch(5, vector <int>(5));

void dfs(int i, int j, int L)
{
	
	
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> vec[i][j];
		}
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (ch[i][j] == 0)
			{
				dfs(i, j, vec[i][j]);
			}
		}
	}


	return 0;
}