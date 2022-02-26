#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int mini = 987654321;

	vector <vector<int>> vec(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> vec[i][j];
		}
	}

	vector<int> ch(n + 1);

	for (int i = 1; i <= n; i++)
	{
		if (i <= n / 2)
		{
			ch[i] = 1;
		}
		else
		{
			ch[i] = 0;
		}
	}

	do
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{

			}
		}

	} while (next_permutation(ch.begin(), ch.end()));


	cout << mini;

	return 0;
}