#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int chan = 100;

int N;
int M;

vector <int> remote(10, 1);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	if (M == 10)
	{
		cout << abs(N - chan);
		return 0;
	}

	for (int i = 1; i <= M; i++)
	{
		int push;
		cin >> push;
		remote[push] = 0;
	}

	int plus = N;
	int minus = N;

	int res = 0;
	vector <int> com;

	bool exit = false;

	while (1)
	{
		string plus_s = to_string(plus);

		bool b = true;
		for (int i = 0; i < plus_s.size(); i++)
		{
			if (remote[plus_s[i] - '0'] == 0)
			{
				b = false;
				break;
			}
		}

		if (b == true)
		{
			res = (plus - N) + plus_s.size();
			exit = true;
			com.push_back(res);
		}

		plus++;

		if (minus >= 0)
		{
			string minus_s = to_string(minus);

			b = true;
			for (int i = 0; i < minus_s.size(); i++)
			{
				if (remote[minus_s[i] - '0'] == 0)
				{
					b = false;
					break;
				}
			}

			if (b == true)
			{
				res = abs(minus - N) + minus_s.size();
				exit = true;
				com.push_back(res);
			}

			minus--;
		}

		if (exit == true)
			break;
	}

	com.push_back(abs(N - chan));

	int min = 987654321;

	for (int i = 0; i < com.size(); i++)
	{
		if (min > com[i])
		{
			min = com[i];
		}
	}

	cout << min;


	return 0;
}