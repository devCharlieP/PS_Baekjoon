#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;

	int i;
	cin >> i;

	cout << S[i - 1];

	return 0;
}