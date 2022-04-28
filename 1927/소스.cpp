#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

vector <int> vec_heap(100001);
int vec_heapSize = 0;

void heap_push(int x)
{
	vec_heap[++vec_heapSize] = x;

	int child = vec_heapSize;
	int parent = child / 2;

	int temp = 0;

	while (child > 1 && vec_heap[child] < vec_heap[parent])
	{
		swap(vec_heap[child], vec_heap[parent]);

		child = parent;
		parent = child / 2;
	}
}

int heap_pop()
{
	int res = vec_heap[1];

	vec_heap[1] = vec_heap[vec_heapSize--];

	int parent = 1;
	int child = parent * 2;

	if (child + 1 <= vec_heapSize)
	{
		if (vec_heap[child] > vec_heap[child + 1])
		{
			child = child + 1;
		}
	}

	while (child <= vec_heapSize && vec_heap[parent] > vec_heap[child])
	{
		swap(vec_heap[parent], vec_heap[child]);

		parent = child;
		child = parent * 2;

		if (child + 1 <= vec_heapSize)
		{
			if (vec_heap[child] > vec_heap[child + 1])
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

	int x;
	vector <int> vec_x;

	for (int i = 1; i <= N; i++)
	{
		cin >> x;
		vec_x.push_back(x);
	}

	for (int i = 0; i < N; i++)
	{
		if (vec_x[i] == 0)
		{
			if (vec_heapSize == 0)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << heap_pop() << endl;
			}
		}
		else
		{
			heap_push(vec_x[i]);
		}
	}

	return 0;
}