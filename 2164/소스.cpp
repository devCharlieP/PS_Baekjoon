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

	int N;
	cin >> N;

	queue <int> Q;

	for (int i = 1; i <= N; i++)
	{
		Q.push(i);
	}

	while (Q.size() != 1)
	{
		Q.pop();

		int temp = Q.front();

		Q.pop();
		
		Q.push(temp);
	}

	cout << Q.front();

	return 0;
}