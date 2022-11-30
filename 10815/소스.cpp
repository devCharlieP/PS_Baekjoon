#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

vector <int> card;

int find(int push)
{
	int left = 0;
	int right = card.size() - 1;
	int mid = (left + right) / 2;

	if (push < card[left] || push > card[right])
	{
		return 0;
	}

	while (left <= right)
	{
		if (push < card[mid])
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else if (push > card[mid])
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else
		{
			return 1;
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

	card = vector <int> (N);

	for (int i = 0; i < N; i++)
	{
		cin >> card[i];
	}

	sort(card.begin(), card.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int push;
		cin >> push;
		cout << find(push) << " ";
	}

	return 0;
}