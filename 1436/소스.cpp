#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = 0;
	int result = 0;
	string str666 = "666";

	for (int i = 100; ; i++)
	{
		string str = to_string(i);

		for (int j = 0; j < str.size() - str666.size() + 1; j++)
		{
			if (str.substr(j, 3) == str666)
			{
				count++;
				break;
			}
		}
		
		if (count == n)
		{
			result = i;
			break;
		}
	}

	cout << result;

	return 0;
}