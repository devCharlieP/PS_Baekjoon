#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	queue <int> Q;

	for (int i = 1; i <= N; i++)
	{
		Q.push(i);
	}

	vector <int> res;

	int i = 0;

	while (!Q.empty())
	{
		int push = Q.front();
		Q.pop();

		i++;

		if (i == K)
		{
			i = 0;
			res.push_back(push);
		}
		else
		{
			Q.push(push);
		}
	}

	cout << "<";

	for (int i = 0; i < res.size(); i++)
	{
		if (i != res.size() - 1)
		{
			cout << res[i] << ", ";
			
		}
		else
		{
			cout << res[i] << ">";
		}	
	}

	return 0;
}