#include <iostream>
#include <vector>
#include <algorithm>
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
		int push;
		cin >> push;
		vec.push_back(push);
	}

	sort(vec.begin(), vec.end());

	dfs(0, m, result);

	return 0;
}