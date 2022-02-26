#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

string swap(string s)
{
	char c = NULL;

	c = s.at(0);
	s.at(0) = s.at(1);
	s.at(1) = c;

	return s;
}

int main()
{
	int n, m;

	cin >> n >> m;

	string s;
	string s1;
	vector <int> numv;
	vector <string> arr;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		arr.push_back(s);
	}

	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			s1 = "BW";
			int num = 0;
			int num2 = 0;

			for(int n = 0; n < 2; n++)
			{
				for (int k = i; k < i + 8; k++)
				{
					int m = 0;

					for (int l = j; l < j + 8; l++)
					{
						if (arr.at(k).at(l) != s1.at(m % 2))
						{
							if (n == 0)
								num++;

							if (n == 1)
								num2++;					
						}
						m++;
					}
					s1 = swap(s1);				
				}
				s1 = swap(s1);
			}
			numv.push_back(min(num, num2));
		}
	}

	int min = numeric_limits<int>::max();

	for (int i = 0; i < numv.size(); i++)
	{
		if (numv.at(i) < min)
		{
			min = numv.at(i);
		}
	}

	cout << min;

	return 0;
}