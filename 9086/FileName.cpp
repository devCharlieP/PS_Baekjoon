#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) 
	{
		string s;
		cin >> s;

		cout << s[0] << s[s.size() - 1] << endl;
	}

	return 0;
}