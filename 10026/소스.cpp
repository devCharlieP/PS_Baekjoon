#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int N;
vector <string> RGB(101);
vector <vector <int>> ch(101, vector <int>(101));
vector <int> di = {-1, 1, 0, 0};
vector <int> dj = {0, 0, -1, 1};
int res1 = 0, res2 = 0;

void dfs(int Ai, int Aj, char C)
{
	int Adi = 0;
	int Adj = 0;

	for (int i = 0; i < 4; i++)
	{
		Adi = Ai + di[i];
		Adj = Aj + dj[i];

		if (Adi >= 0 && Adi < N && Adj >= 0 && Adj < N)
		{
			if (C == RGB[Adi][Adj] && ch[Adi][Adj] == 0)
			{
				ch[Adi][Adj] = 1;
				dfs(Adi, Adj, RGB[Adi][Adj]);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> RGB[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (ch[i][j] == 0)
			{
				ch[i][j] = 1;
				dfs(i, j, RGB[i][j]);
				res1++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (RGB[i][j] == 'G')
			{
				RGB[i][j] = 'R';
			}
		}
	}

	ch = vector <vector <int>>(101, vector <int>(101));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (ch[i][j] == 0)
			{
				ch[i][j] = 1;
				dfs(i, j, RGB[i][j]);
				res2++;
			}
		}
	}

	cout << res1 << " " << res2;

	return 0;
}