#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int X;
	cin >> X;

	vector<int> vec = { 64, 32, 16, 8, 4, 2, 1 };

	int res = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		if (X >= vec[i])
		{
			X = X % vec[i];
			res++;
		}
	}

	cout << res;

	return 0;
}