#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector <string> deut_vec;

	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		deut_vec.push_back(s);
	}

	sort(deut_vec.begin(), deut_vec.end());

	map <string, int> bo_map;

	for (int i = 1; i <= M; i++)
	{
		string s;
		cin >> s;
		bo_map.insert({ s, i });
	}

	vector <string> res;

	for (int i = 0; i < deut_vec.size(); i++)
	{
		if (bo_map.find(deut_vec[i]) != bo_map.end())
		{
			res.push_back(deut_vec[i]);
		}
	}

	cout << res.size() << endl;

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}

	return 0;
}