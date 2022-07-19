#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		string p;
		cin >> p;

		int n;
		cin >> n;

		string x;
		cin >> x;

		deque <int> D;
		bool b = true;

		vector <int> vec;

		if (n != 0)
		{
			for (int i = 1; i < x.size(); i++)
			{
				int sum = 0;

				if (x[i] - '0' >= 0 && x[i] - '0' <= 9)
				{
					vec.push_back(x[i] - '0');
				}
				else
				{
					for (int j = 0; j < vec.size(); j++)
					{
						sum += vec[j] * pow(10, vec.size() - 1 - j);
					}

					D.push_back(sum);
					vec.clear();
				}
			}
		}

		int R = 0;

		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
			{
				R++;
			}
			else
			{
				if (D.size() == 0)
				{
					b = false;
				}
				else
				{
					if (R % 2 == 0)
					{
						D.pop_front();
					}
					else
					{
						D.pop_back();
					}
				}
			}

			if (b == false)
			{
				break;
			}
		}

		if (b == true)
		{
			cout << "[";

			if (R % 2 == 0)
			{
				for (int i = 0; i < D.size(); i++)
				{
					if (i != D.size() - 1)
					{
						cout << D[i] << ",";
					}
					else
					{
						cout << D[i];
					}
				}
			}
			else
			{
				for (int i = D.size() - 1; i >= 0; i--)
				{
					if (i != 0)
					{
						cout << D[i] << ",";
					}
					else
					{
						cout << D[i];
					}
				}

			}

			cout << "]" << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}

	return 0;
}