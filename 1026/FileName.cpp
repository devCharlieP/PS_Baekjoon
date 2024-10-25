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

	vector<int> B(N);
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}

	sort(A.begin(), A.end());

	sort(B.begin(), B.end(), greater<int>());

	int res = 0;
	for (int i = 0; i < N; i++)
	{
		res += A[i] * B[i];
	}

	cout << res;

	return 0;
}