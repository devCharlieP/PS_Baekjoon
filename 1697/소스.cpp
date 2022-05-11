#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
vector <int> ch(100001, -1);

int bfs(int n, int k)
{
	int front = 0;

	queue <int> Q;
	Q.push(n);

	ch[n] = 0;

	while (!Q.empty())
	{
		front = Q.front();

		if (front == k)
		{
			break;
		}

		Q.pop();

		if (front - 1 >= 0 && ch[front - 1] == -1)
		{
			Q.push(front - 1);
			ch[front - 1] = ch[front] + 1;
		}

		if (front + 1 <= 100000 && ch[front + 1] == -1)
		{
			Q.push(front + 1);
			ch[front + 1] = ch[front] + 1;
		}

		if (front * 2 <= 100000 && ch[front * 2] == -1)
		{
			Q.push(front * 2);
			ch[front * 2] = ch[front] + 1;
		}
	}

	return ch[k];
}	

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	cout <<	bfs(N, K);

	return 0;
}