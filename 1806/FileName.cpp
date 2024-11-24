#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;

	vector<int> vec(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	int start = 0;
	int end = 0;

	int res = INT_MAX;

	int sum = vec[0];

	while (end < N)
	{
		if (sum >= S)
		{
			if (start == end)
			{
				res = 1;
				break;
			}
			else
			{
				res = min(res, end - start + 1);

				sum -= vec[start];
				start++;
			}
		}
		else
		{
			end++;

			if (end < N)
			{
				sum += vec[end];
			}			
		}
	}

	if (res == INT_MAX)
	{
		cout << 0;
	}
	else
	{
		cout << res;
	}	

	return 0;
}