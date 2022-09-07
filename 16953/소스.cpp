#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int A, B;

int dfs(int x, int cnt)
{
	if (x == B)
	{
		return cnt;
	}
	dfs(x * 2, cnt + 1);
	dfs(x * 10 + 1, cnt + 1);
	
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> A >> B;


	cout << dfs(A, 0);

	return 0;
}