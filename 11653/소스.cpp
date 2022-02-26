#include <iostream>
#include <vector>
using namespace std;

vector <int> eratos(int n)
{
	vector <bool> vec(n + 1, false);

	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			vec[i] = true;
		}
	}

	vector <int> sos;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == true)
		{
			sos.push_back(i);
		}
	}

	return sos;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	if (n == 1)
	{
		return 0;
	}

	vector <int> vec = eratos(n);

	while(n > 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (n % vec[i] == 0)
			{
				cout << vec[i] << "\n";
				n /= vec[i];
				break;
			}
		}
	}
	
	return 0;
}