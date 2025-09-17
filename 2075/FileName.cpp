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

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N * N; i++)
	{
		int temp;
		cin >> temp;

		pq.push(temp);

		if (pq.size() > N)
		{
			pq.pop();
		}
	}

	cout << pq.top();

	return 0;
}