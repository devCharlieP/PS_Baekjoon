#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	map<string, int> S;

	for (int i = 0; i < N; i++)
	{
		string push;
		cin >> push;
		
		S.insert({ push, i });
	}

	int cnt = 0;

	for (int i = 0; i < M; i++)
	{
		string push;
		cin >> push;

		if (S.find(push) != S.end())
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}