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

	int A, B;
	cin >> A >> B;

	vector <int> cnt(1000000001);

	queue<int> Q;
	Q.push(A);

	while (!Q.empty())
	{
		int front = Q.front();
		Q.pop();

		if (front <= 500000000 && cnt[front * 2] == 0)
		{
			Q.push(front * 2);
			cnt[front * 2] = cnt[front] + 1;
		}
		
		if (front <= 99999999)
		{
			
			Q.push((front * 10) + 1);
			cnt[(front * 10) + 1] = cnt[front] + 1;
		}
		else
		{

		}
	}

	if (cnt[B] == 0)
	{
		cout << -1;
	}
	else
	{
		cout << cnt[B] + 1;
	}

	return 0;
}