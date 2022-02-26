#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int dp(int n, int cnt)
{
	if (n < 1)
	{
		return cnt;
	}
	if (n == 1)
	{
		return cnt;
	}
	
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	dp(n, 0);

	return 0;
}