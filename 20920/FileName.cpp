#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define endl '\n'
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	
	if (a.second == b.second)
	{
		if (a.first.size() == b.first.size())
		{
			return a.first < b.first;
		}

		return a.first.size() > b.first.size();
	}
	
	return a.second > b.second;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	map <string, int> word;

	string temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		if (word.find(temp) != word.end())
		{
			auto iter = word.find(temp);
			iter->second = iter->second + 1;
		}
		else
		{
			if (temp.size() >= M)
			{
				word.insert({ temp, 1 });
			}
		}
	}

	vector<pair<string, int>> vec(word.begin(), word.end());

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << endl;
	}
	
	return 0;
}