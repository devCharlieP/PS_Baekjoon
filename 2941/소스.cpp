#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num = 0;
	string s;
	cin >> s;
	
	string cro[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < sizeof(cro) / sizeof(cro[0]); j++)
		{
			if (s.substr(i, cro[j].size()) == cro[j])
			{
				i = i + cro[j].size() - 1;
				break;
			}
		}
		num++;
	}

	cout << num;

	return 0;
}