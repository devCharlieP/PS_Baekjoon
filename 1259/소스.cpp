#include <iostream>
#include <algorithm>
#include <string>

#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	bool b;

	while(1)
	{
		b = true;
		cin >> s;

		if (s == "0")
		{
			break;
		}
		
		int size = s.size();

		for (int i = 0; i <= (size / 2) - 1; i++)
		{
			if (s[i] != s[size - i - 1])
			{
				b = false;
				break;
			}
		}

		if (b == true)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}

	}

	return 0;
}