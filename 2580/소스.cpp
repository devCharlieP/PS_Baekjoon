#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

vector <vector<int>> sudoku(9, vector<int>(9));
int row_f, col_f = 0;

void dfs(int row, int col)
{
	for (int t = 1; t <= 9; t++)
	{
		sudoku[row][col] = t;

		bool flag = true;

		//같은 열, 같은 행 검사
		for (int i = 0; i < 9; i++)
		{
			if (sudoku[row][i] == t && i != col)
			{
				flag = false;
				break;
			}

			if (sudoku[i][col] == t && i != row)
			{
				flag = false;
				break;
			}
		}

		//3X3 정사각형 검사
		if (flag == true)
		{
			int row_t = row / 3 * 3;
			int col_t = col / 3 * 3;

			for (int i = row_t; i < row_t + 3; i++)
			{
				for (int j = col_t; j < col_t + 3; j++)
				{
					if (sudoku[i][j] == t && i != row && j != col)
					{
						flag = false;
					}
				}
			}
		}

		if (flag == true)
		{
			//스도쿠 완성 및 출력
			if (row == row_f && col == col_f)
			{
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						cout << sudoku[i][j] << " ";
					}

					cout << endl;
				}

				exit(0);
			}

			bool b = false;

			//다음 0으로 
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (sudoku[i][j] == 0)
					{
						dfs(i, j);

						sudoku[i][j] = 0;
						b = true;
						break;
					}
				}

				if (b == true)
					break;
			}
		}
	}

	return;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];

			if (sudoku[i][j] == 0)
			{
				row_f = i;
				col_f = j;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[i][j] == 0)
			{
				dfs(i, j);
			}
		}
	}

	return 0;
}