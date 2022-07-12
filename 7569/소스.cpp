#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

int M, N, H;
vector <vector <int>> tomato(10001, vector<int>(101));

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N >> H;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				cin >> tomato[j + ((i - 1) * N)][k];
			}
		}
	}

	queue <pair<int, int>> Q;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (tomato[j + ((i - 1) * N)][k] == 1)
				{
					Q.push(make_pair(j + ((i - 1) * N), k));
				}
			}
		}
	}

	vector <pair<int, int>> vec_pair = {make_pair(N, 0), make_pair(-N, 0),
		make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};

	int res = 0;
	pair<int, int> back = Q.back();
	pair<int, int> front;

	while (!Q.empty())
	{
		front = Q.front();
		Q.pop();

		for (int i = 0; i < 6; i++)
		{
			bool b = true;
			int first = front.first + vec_pair[i].first;
			int second = front.second + vec_pair[i].second;

			if (first >= 1 && first <= (N * H) && second >= 1 && second <= M)
			{
				if (i == 2)
				{
					if (first % N == 0)
					{
						b = false;
					}
				}

				if (i == 3)
				{
					if (first % N == 1)
					{
						b = false;
					}
				}

				if (tomato[first][second] == -1 || tomato[first][second] == 1)
				{
					b = false;
				}

				if (b == true)
				{
					tomato[first][second] = 1;
					Q.push(make_pair(first, second));
				}
			}			
		}

		if (!Q.empty() && (front == back))
		{
			res++;
			back = Q.back();

			cout << endl;

			for (int i = 1; i <= H; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					for (int k = 1; k <= M; k++)
					{
						cout << tomato[j + ((i - 1) * N)][k] << "  ";
					}
					cout << endl;
				}
			}
		}
	}

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (tomato[j + ((i - 1) * N)][k] == 0)
				{
					res = -1;
				}
			}
		}
	}

	cout << res;

	return 0;
}