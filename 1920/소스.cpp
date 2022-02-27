#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

vector <int> vec_A;
int binary_search(int value, int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (vec_A[mid] == value)
		{
			return 1;
		}
		else if (vec_A[mid] > value)
		{
			right = mid - 1;
		}
		else if(vec_A[mid] < value)
		{
			left = mid + 1;
		}
	}

	return 0;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vec_A = vector <int>(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec_A[i];
	}

	sort(vec_A.begin(), vec_A.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		cout << binary_search(temp, 0, N - 1) << endl;
	}

	return 0;
}