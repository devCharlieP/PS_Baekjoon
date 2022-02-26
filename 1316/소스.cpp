#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{	
	int n;
	int a = 0;
	int b = 0;
	int num = 0;

	cin >> n;

	vector <string> str(n);

	for (int i = 0; i < n; i++)
	{
		cin >> str.at(i);
	}

	for (int i = 0; i < n; i++)
	{
		b = 0;

		for (int j = 0; j < str.at(i).size(); j++)
		{
			a = 0;
			for (int k = j + 1; k < str.at(i).size(); k++)
			{
				if (str.at(i).at(j) == str.at(i).at(k))
				{
					if (a >= 1 && b < 1)
					{
						num++;
						b++;
						break;
					}
					continue;
				}
				a++;
			}
		}
	}

	cout << n - num;

	return 0;
}