#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while(!cin.eof())
	{
		int n;
		cin >> n;

		if (cin.eof())
		{
			break;
		}

		int cnt = 1;
		int num = 0;

		if (n == 1)
		{
			cout << 1 << "\n";
		}
		else
		{
			while (1)
			{
				for (int i = n; i < n * 10; i += n)	
				{
					if ((num + i) % 10 == 1)
					{
						num += i;

						while (num % 10 == 1 && num > 1)
						{
							num /= 10;
							cnt++;
						}

						break;
					}
				}

				if (num % 10 == 1)
				{
					break;
				}

			}

			cout << cnt << "\n";
		}
	}

	return 0;
}