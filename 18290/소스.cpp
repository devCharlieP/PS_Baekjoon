#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
vector <vector<int>> vec(11, vector<int>(11));
vector <vector<int>> ch(11, vector<int>(11));

vector <vector<int>> vec_empty(11, vector<int>(11));
vector <int> dx = { 0, 0, -1, 1};
vector <int> dy = { 1, -1, 0, 0};
int maxi = -987654321;
bool b = true;

void dp(int sum, int cnt)
{
	if (cnt == k)
	{
		if (sum > maxi)
		{
			maxi = sum;
		}

		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				for (int t = 0; t < 4; t++)
				{
					if (i + dy[t] >= 1 && i + dy[t] <= n && j + dx[t] >= 1 && j + dx[t] <= m)
					{
						if (ch[i + dy[t]][j + dx[t]] == 1)
						{
							b = false;
						}
					}
				}

				if (ch[i][j] == 0 && b == true)
				{
					ch[i][j] = 1;
					dp(sum + vec[i][j], cnt + 1);
					ch[i][j] = 0;
				}

				b = true;
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> vec[i][j];
		}
	}

	dp(0, 0);
	
	cout << maxi;

	return 0;
}