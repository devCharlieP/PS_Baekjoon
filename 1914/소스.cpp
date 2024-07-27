#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

string hanoi_num(int n)
{
	string s = to_string(pow(2, n));
	s = s.substr(0, s.find("."));
	s[s.size() - 1] -= 1;

	return s;
}

void hanoi_order(int n, int a, int b, int c)
{
	if (n == 1)
	{
		cout << a << " " << c << endl;
	}
	else
	{
		hanoi_order(n - 1, a, c, b);

		cout << a << " " << c << endl;

		hanoi_order(n - 1, b, a, c);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	string s = hanoi_num(N);
	cout << s << endl;

	if (N <= 20)
	{
		hanoi_order(N, 1, 2, 3);
	}

	return 0;
}