#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

struct melon
{
	int dir;
	int len;
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int K;
	cin >> K;

	vector <melon> map(20);

	for (int i = 0; i <= 5; i++)
	{
		int x, y;
		cin >> x >> y;
		map[i] = melon{ x, y };
		map[i + 6] = melon{ x, y };
		map[i + 12] = melon{ x, y };
	}

	int max = 0;
	int loc = 0;

	for (int i = 6; i < 12; i++)
	{
		if (max < map[i].len)
		{
			max = map[i].len;
			loc = i;
		}
	}

	int size = 0;

	if (map[loc - 1].len > map[loc + 1].len)
	{
		size = (map[loc].len * map[loc + 1].len) + (map[loc + 3].len * map[loc + 4].len);
	}
	else
	{
		size = (map[loc].len * map[loc - 1].len) + (map[loc - 3].len * map[loc - 4].len);
	}

	cout << K * size;

	return 0;
}