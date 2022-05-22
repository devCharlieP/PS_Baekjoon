#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int N;
vector <pair<int, int>> meeting;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	int x, y;
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		meeting.push_back(make_pair(y, x));
	}

	sort(meeting.begin(), meeting.end());

	int cnt = 0;
	int temp = 0;

	for (int i = 0; i < N; i++)
	{
		if (temp <= meeting[i].second)
		{
			cnt++;
			temp = meeting[i].first;
		}
	}

	cout << cnt;

	return 0;
}