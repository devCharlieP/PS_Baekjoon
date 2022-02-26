#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long num = 1000000009;

vector <vector<long long>> vec(100001, vector <long long> (4, 0));

void dp(int n)
{
	vec[1][1] = vec[2][2] = vec[3][1] = vec[3][2] = vec[3][3] = 1;

	for (int i = 4; i <= n; i++)
	{
		vec[i][1] = (vec[i - 1][2] + vec[i - 1][3]) % num;
		vec[i][2] = (vec[i - 2][1] + vec[i - 2][3]) % num;
		vec[i][3] = (vec[i - 3][1] + vec[i - 3][2]) % num;
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;

	dp(100000);

	for (int i = 1; i <= T; i++)
	{
		int n;
		cin >> n;
		cout << (vec[n][1] + vec[n][2] + vec[n][3]) % num;
		cout << endl;
	}
	return 0;
}