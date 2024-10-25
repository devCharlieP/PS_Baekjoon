#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	vector<int> res;
	
	for (int i = 0; i < N; i++)
	{
		if (res.size() == 0 || A[i] > res[res.size() - 1])
		{
			res.push_back(A[i]);
		}
		else
		{
			*lower_bound(res.begin(), res.end(), A[i]) = A[i];
		}
	}

	cout << res.size();

	return 0;
}