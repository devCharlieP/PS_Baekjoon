#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;

	cout << A + B - C << endl;

	cout << stoi(to_string(A) + to_string(B)) - C;

	return 0;
}