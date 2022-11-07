#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int total;
	int num;

	cin >> total >> num;

	int a, b;
	int sum = 0;

	for (int i = 1; i <= num; i++)
	{
		cin >> a >> b;
		sum += a * b;

	}

	if (total == sum)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}