#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl "\n"

int N;
vector <vector <int>> quadTree(64, vector<int>(64));

void rec(int x, int y, int Level)
{
	bool b = true;

	for (int i = x; i < x + Level; i++)
	{
		for (int j = y; j < y + Level; j++)
		{
			if (quadTree[x][y] != quadTree[i][j])
			{
				b = false;
				break;
			}
		}

		if (b == false)
		{
			break;
		}
	}

	if (b == true)
	{
		cout << quadTree[x][y];
	}
	else
	{
		cout << "(";
		rec(x, y, Level / 2);
		rec(x, y + Level / 2, Level / 2);
		rec(x + Level / 2, y, Level / 2);
		rec(x + Level / 2, y + Level / 2, Level / 2);
		cout << ")";
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	string s;

	for (int i = 0; i < N; i++)
	{
		cin >> s;

		for (int j = 0; j < N; j++)
		{
			quadTree[i][j] = s[j] - '0';
		}
	}

	rec(0, 0, N);

	return 0;
}