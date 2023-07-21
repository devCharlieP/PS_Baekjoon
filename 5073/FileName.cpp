#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> a(3);

	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> a[i];
		}

		if (a[0] == 0 && a[1] == 0 && a[2] == 0)
		{
			break;
		}

		int max_a = -1;
		int sum = 0;

		for (int i = 0; i < 3; i++)
		{
			max_a = max(max_a, a[i]);
			sum += a[i];
		}

		sum -= max_a;

		if (max_a >= sum)
		{
			cout << "Invalid" << endl;
		}
		else if (a[0] == a[1] && a[1] == a[2] && a[0] == a[2])
		{
			cout << "Equilateral" << endl;
		}
		else if (a[0] == a[1] || a[0] == a[2] || a[1] == a[2])
		{
			cout << "Isosceles" << endl;
		}
		else
		{
			cout << "Scalene" << endl;
		}
	}

	return 0;
}