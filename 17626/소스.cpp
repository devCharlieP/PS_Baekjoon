#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

vector <int> vec(500001);



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int cnt = 0;

	int max = 1;

	while (pow(max, 2) < n)
	{
		max++;
	}


	cout << cnt;

	return 0;
}