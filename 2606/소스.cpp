#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int com_n, duo_n;
vector <vector <int>> duo_vec(101, vector <int>(101));
vector <int> ch(101);

void dfs(int L)
{
	for (int i = 1; i <= com_n; i++)
	{
		if (duo_vec[L][i] == 1 && ch[i] == 0)
		{
			ch[i] = 1;
			dfs(i);
		}
	}

	return;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> com_n >> duo_n;

	int x, y;

	for (int i = 1; i <= duo_n; i++)
	{
		cin >> x >> y;

		duo_vec[x][y] = 1;
		duo_vec[y][x] = 1;
	}

	ch[1] = 1;
	dfs(1);

	int virus_n = 0;

	for (int i = 2; i <= com_n; i++)
	{
		if (ch[i] == 1)
		{
			virus_n++;
		}
	}

	cout << virus_n;

	return 0;
}