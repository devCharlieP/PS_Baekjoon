#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int od;

	vector<int> vec;

	for (int i = 1; i <= N; i++)
	{
		cin >> od;

		int num;

		if (od == 1)
		{
			cin >> num;

			vec.push_back(num);
		}
		else if (od == 2)
		{
			if (vec.size() == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << vec[vec.size() - 1] << endl;
				vec.pop_back();
			}
		}
		else if (od == 3)
		{
			cout << vec.size() << endl;
		}
		else if (od == 4)
		{
			if (vec.size() == 0)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}

		}
		else if (od == 5)
		{
			if (vec.size() == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << vec[vec.size() - 1] << endl;
			}
		}
	}

	return 0;
}