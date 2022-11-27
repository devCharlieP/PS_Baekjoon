#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int N = 0, K = 0, cnt = 0;
vector <int> tmp;

void merge_s(vector <int> &A, int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int t = 1;

	while (i <= q && j <= r)
	{
		if (A[i] <= A[j])
		{
			tmp[t++] = A[i++];
		}
		else
		{
			tmp[t++] = A[j++];
		}
	}

	while (i <= q)
	{
		tmp[t++] = A[i++];
	}

	while (j <= r)
	{
		tmp[t++] = A[j++];
	}

	i = p;
	t = 1;

	while (i <= r)
	{
		A[i++] = tmp[t++];
		cnt++;

		if (cnt == K)
		{
			cout << A[i - 1];
		}
	}
}

void merge_sort(vector<int> &A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;

		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge_s(A, p, q, r);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	vector <int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	tmp = vector <int> (N + 1);

	merge_sort(arr, 0, N - 1);

	if (cnt < K)
	{
		cout << -1;
	}

	return 0;
}