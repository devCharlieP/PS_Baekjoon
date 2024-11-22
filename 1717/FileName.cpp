#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

vector<int> parent;

int find(int x)
{
	if (x == parent[x])
	{
		return x;
	}
	
	return parent[x] = find(parent[x]);
}

void unions(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a > b)
	{
		parent[a] = b;
	}
	else
	{
		parent[b] = a;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	parent.resize(n + 1);

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 0)
		{
			unions(a, b);
		}
		else
		{
			if (find(a) == find(b))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}

	return 0;
}