#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;


int N, M, B;
vector <vector <int>> vec(501, vector<int>(501));

void dfs(int k, int l, int inv)
{
	int ch_temp = vec[0][0];
	bool ch_bool = true;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ch_temp != vec[i][j])
			{
				ch_bool = false;
				break;
			}
		}

		if (ch_bool == false)
		{
			break;
		}
	}

	if (ch_bool == false)
	{
		if (vec[k][l] == 0)
		{
			vec[k][l]++;
			dfs(k, l, inv - 1);
			vec[k][l]--;

			if (k == N - 1)
			{
				dfs(k + 1, 0, inv);
			}
			else
			{
				dfs(k, l + 1, inv);
			}
		}
		else if (vec[k][l] == 256)
		{

		}
		else
		{

		}
			
	}
	else
	{

	}

	
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> vec[i][j];
		}
	}

	dfs(0, 0, B);

	return 0;
}