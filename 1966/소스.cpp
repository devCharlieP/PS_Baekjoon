#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	int N, M;

	for (int i = 1; i <= T; i++)
	{
		cin >> N >> M;

		queue <int> Q;
		vector <int> rank;

		for (int j = 0; j < N; j++)
		{
			Q.push(j);

			int push;
			cin >> push;
			rank.push_back(push);
		}

		int cnt = 1;
		queue <int> Q_save;

		while (!Q.empty())
		{
			bool b = false;
			Q_save = Q;

			while (!Q_save.empty())
			{
				if (rank[Q.front()] < rank[Q_save.front()])
				{
					int front = Q.front();
					Q.pop();
					Q.push(front);
					b = true;

					break;
				}

				Q_save.pop();
			}

			if (b == false)
			{
				if (Q.front() == M)
				{
					cout << cnt << endl;
					break;
				}
				else
				{
					cnt++;
					Q.pop();
				}
			}
		}
	}

	return 0;
}