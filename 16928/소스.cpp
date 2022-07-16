#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl "\n"
using namespace std;

int N, M;
vector <int> Snake(101);
vector <int> ch(101);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 1; i <= 100; i++)
	{
		Snake[i] = i;
	}

	cin >> N >> M;

	for (int i = 1; i <= N + M; i++)
	{
		int p1, p2;
		cin >> p1 >> p2;
		Snake[p1] = p2;
	}

	queue <int> Q;
	Q.push(1);

	while (!Q.empty())
	{
		int front = Q.front();
		Q.pop();

		int pos = 0;

		for (int i = 1; i <= 6; i++)
		{
			pos = front + i;

			if (pos <= 100)
			{
				pos = Snake[pos];

				if (ch[pos] == 0)
				{
					ch[pos] = ch[front] + 1;
					Q.push(pos);
				}
			}
		}
	}

	cout << ch[100];

	return 0;
}