#include <iostream>
#include <vector>
using namespace std;

int d(int n)
{
	int sum = n;

	while (1)
	{
		if (n < 10)
		{
			sum += n;
			break;
		}
		else
		{
			sum += n % 10;
			n = n / 10;
		}
	}
		
	return sum;

}

int main()
{
	vector <int> arr(10000);

	for (int i = 0; i < 10000; i++)
	{
		arr.at(i) = i;
	}

	for (int i = 1; i < 10000; i++)
	{
		if (d(i) >= 10000)
		{
			continue;
		}
		else
		{
			arr.at(d(i)) = 0;
		}
	}

	for (int i = 0; i < arr.size(); )
	{
		if (arr.at(i) == 0)
		{
			arr.erase(arr.begin() + i);
		}
		else
		{
			i++;
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr.at(i) << endl;
	}
	
	return 0;
}