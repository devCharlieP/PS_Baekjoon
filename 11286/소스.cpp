#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;

vector <int> heap(100001);
int heapSize = 0;

void enheap(int x)
{
	heapSize++;
	heap[heapSize] = x;

	int child = heapSize;
	int parent = child / 2;

	while (abs(heap[child]) <= abs(heap[parent]))
	{
		if (abs(heap[child]) == abs(heap[parent]))
		{
			if (heap[child] < heap[parent])
			{
				swap(heap[child], heap[parent]);
			}
		}
		else
		{
			swap(heap[child], heap[parent]);
		}
		
		child = parent;
		parent = child / 2;
	}
}

int deheap()
{
	int root = heap[1];

	heap[1] = heap[heapSize];
	heapSize--;

	int parent = 1;
	int child = parent * 2;

	if (child + 1 <= heapSize)
	{
		if (abs(heap[child]) > abs(heap[child + 1]))
		{
			child += 1;
		}
		else if (abs(heap[child]) == abs(heap[child + 1]))
		{
			if (heap[child] > heap[child + 1])
			{
				child += 1;
			}
		}
	}

	while (child <= heapSize && abs(heap[parent]) >= abs(heap[child]))
	{
		if (abs(heap[parent]) == abs(heap[child]))
		{
			if (heap[parent] > heap[child])
			{
				swap(heap[parent], heap[child]);
			}
		}
		else
		{
			swap(heap[parent], heap[child]);
		}

		parent = child;
		child = parent * 2;

		if (child + 1 <= heapSize)
		{
			if (abs(heap[child]) > abs(heap[child + 1]))
			{
				child += 1;
			}
			else if (abs(heap[child]) == abs(heap[child + 1]))
			{
				if (heap[child] > heap[child + 1])
				{
					child += 1;
				}
			}
		}
	}

	return root;
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

	for (int i = 0; i < N; i++)
	{
		if (vecN[i] == 0)
		{
			if (heapSize == 0)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << deheap() << endl;
			}
		}
		else
		{
			enheap(vecN[i]);
		}
	}

	return 0;
}