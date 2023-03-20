#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<string> vec;
	string s;

	while (getline(cin, s))
		vec.push_back(s);

	for (string s : vec)
		cout << s << endl;

	return 0;
}