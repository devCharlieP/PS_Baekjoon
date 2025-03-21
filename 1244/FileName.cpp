#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cntS;
	cin >> cntS;

	vector<int> vecS(cntS + 1);

	for (int i = 1; i <= cntS; i++)
	{
		cin >> vecS[i];
	}

	int cntSt;
	cin >> cntSt;

	for (int i = 0; i < cntSt; i++)
	{
		int gen, num;
		cin >> gen >> num;

		if (gen == 1)
		{
			for (int j = num; j <= cntS; j += num)
			{
				if (vecS[j] == 0)
				{
					vecS[j] = 1;
				}
				else
				{
					vecS[j] = 0;
				}
			}
		}
		else
		{
			int left = num - 1;
			int right = num + 1;

			while (left >= 1 && right <= cntS)
			{
				if (vecS[left] != vecS[right])
				{
					break;
				}
				else
				{
					left--;
					right++;
				}
			}

			for (int j = left + 1; j < right; j++)
			{
				if (vecS[j] == 0)
				{
					vecS[j] = 1;
				}
				else
				{
					vecS[j] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= cntS; i++)
	{
		cout << vecS[i] << " ";

		if (i % 20 == 0)
		{
			cout << endl;
		}
	}

	return 0;
}