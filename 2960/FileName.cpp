#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int cnt = 0;
	vector<int> vec(N + 1);

	for (int i = 2; i <= N; i++)
	{
		for (int j = i; j <= N; j += i)
		{
			if (vec[j] == 0)
			{
				cnt++;
				vec[j] = 1;

				if (cnt == K)
				{
					cout << j;
					return 0;
				}
			}			
		}
	}

	return 0;
}