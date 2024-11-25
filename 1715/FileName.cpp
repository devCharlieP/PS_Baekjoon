#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> cards(N);

	for (int i = 0; i < N; i++)
	{
		cin >> cards[i];
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	
	for (int i = 0; i < N; i++)
	{
		pq.push(cards[i]);
	}

	int res = 0;

	while (pq.size() > 1)
	{
		int top1 = pq.top();
		pq.pop();

		int top2 = pq.top();
		pq.pop();

		res += top1 + top2;

		pq.push(top1 + top2);
	}

	cout << res;

	return 0;
}