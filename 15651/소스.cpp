#include <iostream>
#include <vector>
using namespace std;

vector <int> vec;

void dfs(int cnt, int m, vector <int> result)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		result[cnt] = vec[i];
		dfs(cnt + 1, m, result);
	}
}

int main()

{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector <int> result(m);

	for (int i = 0; i < n; i++)
	{
		vec.push_back(i + 1);
	}

	dfs(0, m, result);

	return 0;
}