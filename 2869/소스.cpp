#include <iostream>
using namespace std;

int main()
{

	int A, B, V;
	int i = 1, r = 0, q = 0;

	cin >> A >> B >> V;

	if ((V - A) % (A - B) != 0)
	{
		cout << (V - A) / (A - B) + 2;
	}
	else
	{
		cout << (V - A) / (A - B) + 1;
	}

	return 0;

}