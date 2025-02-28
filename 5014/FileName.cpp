#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	queue<int> q;
	q.push(S);

	vector<int> cnt(F + 1, -1);
	cnt[S] = 0;

	while (!q.empty())
	{
		int front = q.front();
		
		q.pop();

		if (front + U <= F && cnt[front + U] == -1)
		{
			q.push(front + U);
			cnt[front + U] = cnt[front] + 1;
		}

		if (front - D >= 1 && cnt[front - D] == -1)
		{
			q.push(front - D);
			cnt[front - D] = cnt[front] + 1;
		}
	}

	if (cnt[G] != -1)
	{
		cout << cnt[G];
	}
	else
	{
		cout << "use the stairs";
	}	

	return 0;
}