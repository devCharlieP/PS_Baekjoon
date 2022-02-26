#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vecN;

int binary_search(int push, int left, int right)
{
	int mid = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (push == vecN[mid])
		{
			return mid;
		}
		else if (push < vecN[mid])
		{
			right = mid - 1;
		}
		else if (push > vecN[mid])
		{
			left = mid + 1;
		}
	}

	return -1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;

	vecN = vector <int>(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vecN[i];
	}

	sort(vecN.begin(), vecN.end());

	int M;
	cin >> M;

	int push;
	int mid = 0;
	int cnt = 1;

	vector <int> vec_check(20000002, -1);

	for (int i = 1; i <= M; i++)
	{
		cin >> push;

		if (vec_check[push + 10000000] != -1)
		{
			cout << vec_check[push + 10000000] << " ";
		}
		else
		{
			mid = binary_search(push, 0, N - 1);

			if (mid == -1)
			{
				vec_check[push + 10000000] = 0;
			}
			else
			{
				cnt = 1;
				int i = 1;
				bool left = true;
				bool right = true;

				while (left == true || right == true)
				{
					if (mid - i < 0 || vecN[mid] != vecN[mid - i])
					{
						left = false;
					}
					else
					{
						cnt++;
					}

					if (mid + i >= N || vecN[mid] != vecN[mid + i])
					{
						right = false;
					}
					else
					{
						cnt++;
					}

					i++;
				}

				vec_check[push + 10000000] = cnt;
			}

			cout << vec_check[push + 10000000] << " ";
		}
	}

	return 0;
}