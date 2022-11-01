#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector <int> white = { 1, 1, 2, 2, 2, 8 };

	vector <int> inputVec(6);
	for (int i = 0; i < 6; i++)
	{
		cin >> inputVec[i];
	}

	for (int i = 0; i < 6; i++)
	{
		cout << white[i] - inputVec[i] << " ";
	}

	return 0;
}