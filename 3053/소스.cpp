#include <iostream>
using namespace std;

int main()
{

	double a = 0;
	const double PI = 3.141592653589793238463;

	cin >> a;

	cout << fixed;
	cout.precision(6);
	cout << a * a * PI << endl;
	cout << 2.0 * a * a << endl;

	return 0;
}