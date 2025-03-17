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

	int N, M;
	cin >> N >> M;

	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int temp;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		A.push_back(temp);
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}

	return 0;
}