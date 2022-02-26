#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(const pair<int, string> &a, const pair<int, string> &b) {

	if (a.first < b.first) {
		return true;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;

	vector <pair<int, string>> age_name(n);

	for (int i = 0; i < n; i++)
	{
		cin >> age_name[i].first >> age_name[i].second;
	}

	stable_sort(age_name.begin(), age_name.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		cout << age_name[i].first << " " << age_name[i].second << "\n";
	}

	return 0;
}
