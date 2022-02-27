#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
	
		vector<pair<int, int>> vec(1);

		if (m < n)
		{
			vec.push_back(make_pair(0, m));
			vec.push_back(make_pair(-m, n - m));

			int cnt = 3;
			int gap = n - m;
			int num_x = m - n;
			int num_y = n - m;

			while (vec[cnt].first == (m - n))
			{
				//È¦¼ö
				if (cnt % 2 != 0)
				{
					if (vec[cnt - 2].second + num_x == -1)
					{
						vec.push_back(make_pair(vec[cnt - 2].first + gap, 1));
						num_x = n - m;
					}
					else
					{
						vec.push_back(make_pair(vec[cnt - 2].first + gap, vec[cnt - 2].second + num_x));
					}
				}
				//Â¦¼ö
				else
				{
					if (vec[cnt - 2].second + num_y > min(m, n))
					{
						vec.push_back(make_pair(vec[cnt - 2].first + gap, min(m, n)));

					}
					else if (vec[cnt - 2].second == min(m, n))
					{
						vec.push_back(make_pair(vec[cnt - 2].first + gap, vec[cnt - 4].second));
						num_y = m - n;
					}
					else
					{
						vec.push_back(make_pair(vec[cnt - 2].first + gap, vec[cnt - 2].second + num_y));
					}
				}
			}

			cnt = 1;
			int sum = 0;

			while (1)
			{
				if (cnt == vec.size())
				{
					cout << -1 << "\n";
					break;
				}
				if (vec[cnt].first == (x - y))
				{
					cout << sum + min(x, y) << "\n";
					break;
				}

				cnt++;
				sum += vec[cnt].second;
			}
		}
		else if(m > n)
		{
			vec.push_back(make_pair(0, n));
			vec.push_back(make_pair(n, m - n));

			int cnt = 3;
			int gap = n - m;
			int num_x = n - m;
			int num_y = m - n;

			while (vec[cnt].first == (m - n))
			{
				//È¦¼ö
				if (cnt % 2 != 0)
				{
					if (vec[cnt - 2].second + num_x == -1)
					{
						vec.push_back(make_pair(vec[cnt - 2].first + gap, 1));
						num_x = m - n;
					}
					else
					{
						vec.push_back(make_pair(vec[cnt - 2].first + gap, vec[cnt - 2].second + num_x));
					}
				}
				//Â¦¼ö
				else
				{
					if (vec[cnt - 2].second + num_y > min(m, n))
					{
						vec.push_back(make_pair(vec[cnt - 2].first + gap, min(m, n)));

					}
					else if(vec[cnt - 2].second == min(m, n))
					{
						vec.push_back(make_pair(vec[cnt-2].first + gap, vec[cnt - 4].second));
						num_y = n - m;
					}
					else
					{
						vec.push_back(make_pair(vec[cnt - 2].first + gap, vec[cnt - 2].second + num_y));
					}
				}
			}

			cnt = 1;
			int sum = 0;

			while (1)
			{
				if (cnt == vec.size())
				{
					cout << -1 << "\n";
					break;
				}
				if (vec[cnt].first == (x - y))
				{
					cout << sum + min(x, y) << "\n";
					break;
				}

				cnt++;
				sum += vec[cnt].second;
			}
			
		}
		else
		{
			cout << m << "\n";
		}
	}

	return 0;
}