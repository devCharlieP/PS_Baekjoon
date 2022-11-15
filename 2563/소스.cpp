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

	int N;
	cin >> N;

	vector <vector <int>> whitePaper(100, vector<int>(100));

	int row, col;

	for (int i = 0; i < N; i++)
	{
		cin >> row >> col;

		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				whitePaper[row + j][col + k] = 1;
			}
		}
	}
	
	int sum = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (whitePaper[i][j] == 1)
			{
				sum++;
			}
		}
	}

	cout << sum;

	return 0;
}