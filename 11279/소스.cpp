#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;

vector <int> maxHeap(100001);

int cntHeap = 0;

void pushHeap(int x)
{
	cntHeap++;
	maxHeap[cntHeap] = x;
	
	int child = cntHeap;
	int parent = child / 2;

	while (maxHeap[parent] < maxHeap[child])
	{
		swap(maxHeap[parent], maxHeap[child]);
		child = parent;
		parent = child / 2;
	}
}

int popHeap()
{
	int res = maxHeap[1];

	maxHeap[1] = maxHeap[cntHeap];
	cntHeap--;

	int parent = 1;
	int child = parent * 2;;

	if (child + 1 <= cntHeap)
	{
		if (maxHeap[child] < maxHeap[child + 1])
		{
			child = child + 1;
		}
	}

	while (maxHeap[parent] < maxHeap[child] && child <= cntHeap)
	{
		swap(maxHeap[parent], maxHeap[child]);

		parent = child;
		child = parent * 2;

		if (child + 1 <= cntHeap)
		{
			if (maxHeap[child] < maxHeap[child + 1])
			{
				child = child + 1;
			}
		}
	}

	return res;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector <int> vecN(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vecN[i];
	}

	maxHeap[0] = pow(2, 31) - 1;

	for (int i = 0; i < N; i++)
	{
		if (vecN[i] == 0)
		{
			if (cntHeap == 0)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << popHeap() << endl;
			}
		}
		else
		{
			pushHeap(vecN[i]);
		}
	}

	return 0;
}