#include <iostream>
#include <algorithm>
#include <vector>	

using namespace std;

int Solution(int M, int N, int x, int y)
{
	
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	int M, N, x, y;

	for (int i = 1; i <= T; i++)
	{
		cin >> M >> N >> x >> y;
		cout << Solution(M, N, x, y) << "\n";
	}

	return 0;
}