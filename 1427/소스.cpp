#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector <int> num;

	while (1)
	{
		if (n < 10)
		{
			num.push_back(n);
			break;
		}
		num.push_back(n % 10);
		n /= 10;
	}

	sort(num.begin(), num.end());

	for (int i = num.size() - 1; i >= 0; i--)
	{
		cout << num.at(i);
	}

	return 0;
}