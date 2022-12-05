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

	int num_A, num_B;
	cin >> num_A >> num_B;

	map<int, int> A;
	for (int i = 0; i < num_A; i++)
	{
		int push;
		cin >> push;
		A.insert({ push, push });
	}

	map<int, int> B;
	for (int i = 0; i < num_B; i++)
	{
		int push;
		cin >> push;
		B.insert({ push, push });
	}

	int cnt = 0;

	for (auto iter = A.begin(); iter != A.end(); iter++)
	{
		if (B.find(iter->first) == B.end())
		{
			cnt++;
		}
	}

	for (auto iter = B.begin(); iter != B.end(); iter++)
	{
		if (A.find(iter->first) == A.end())
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}