#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int N;
vector <vector <int>> vec(2188, vector <int>(2188));
int cnt_minus = 0, cnt_zero = 0, cnt_plus = 0;

void rec(int a, int b, int L)
{
	bool bo = true;
	int temp = vec[a][b];

	for (int i = a; i < a + L; i++)
	{
		for (int j = b; j < b + L; j++)
		{
			if (temp != vec[i][j])
			{
				bo = false;
				break;
			}
		}

		if (bo == false)
		{
			break;
		}
	}

	if (bo == false)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				rec(a + (i * (L / 3)), b + (j * (L / 3)), L / 3);
			}
		}
	}
	else
	{
		if (vec[a][b] == -1)
		{
			cnt_minus++;
		}
		else if (vec[a][b] == 0)
		{
			cnt_zero++;
		}
		else
		{
			cnt_plus++;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> vec[i][j];
		}
	}

	rec(1, 1, N);

	cout << cnt_minus << endl << cnt_zero << endl << cnt_plus;

	return 0;
}