#include <iostream>
using namespace std;

int main()
{
	int A;
	int B;

	while(1)
	{
		cin >> A;
		cin >> B;

		if (cin.eof() == true)
		{
			break;
		}

		cout << A + B << endl;
				
	}

	return 0;
}