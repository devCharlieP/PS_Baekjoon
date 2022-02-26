#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	int input;
	int max = 0;

	cin >> n;

	vector<int> count;

	for (int i = 0; i < 10000; i++)
	{
		count.push_back(0);
	}

	for (int i = 0; i < n; i++)
	{
		ios::sync_with_stdio(false);
		cin >> input;
		count[input - 1]++;
		if (max < input)
		{
			max = input;
		}
	}

	for (int i = 0; i < max; i++) 
	{		
		for(int j = 0; j < count[i]; j++) 
		{ 
			ios::sync_with_stdio(false);
			cout << i + 1 << "\n";
		}  
	}

	return 0;
}