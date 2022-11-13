#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector <vector <int>> map(9, vector<int>(9));

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
		}
	}

	int max = -987654321;
	int resRow, resCol;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (max < map[i][j])
			{
				max = map[i][j];
				resRow = i + 1;
				resCol = j + 1;
			}
		}
	}

	cout << max << endl;
	cout << resRow << " " << resCol;

	return 0;
}