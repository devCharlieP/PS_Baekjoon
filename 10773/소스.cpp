#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int K;
	cin >> K;

	stack <int> S;

	for (int i = 1; i <= K; i++)
	{
		int push;
		cin >> push;
		
		if (push != 0)
		{
			S.push(push);
		}
		else
		{
			S.pop();
		}
	}

	int sum = 0;

	while (!S.empty())
	{
		sum += S.top();
		S.pop();
	}

	cout << sum;

	return 0;
}