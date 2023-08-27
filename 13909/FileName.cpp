#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int cnt = 0;

	for (int i = 1; i * i <= N; i++)
	{
		cnt++;
	}

	cout << cnt;

	return 0;
}