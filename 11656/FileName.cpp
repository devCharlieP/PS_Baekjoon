#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	vector<string> vec;

	for (int i = 0; i < s.size(); i++)
	{
		vec.push_back(s.substr(i));
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}

	return 0;
}