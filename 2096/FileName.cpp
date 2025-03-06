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

	int N;
	cin >> N;

	vector<int> dpMax(3);
	vector<int> dpMin(3);

	for (int i = 0; i < 3; i++)
	{
		cin >> dpMax[i];
		dpMin[i] = dpMax[i];
	}

	vector<int> temp(3);
	vector<int> input(3);

	for (int i = 1; i < N; i++)
	{
		cin >> input[0] >> input[1] >> input[2];

		temp[0] = dpMax[0];
		temp[1] = dpMax[1];
		temp[2] = dpMax[2];

		dpMax[0] = max(temp[0], temp[1]) + input[0];
		dpMax[1] = max(max(temp[0], temp[1]), temp[2]) + input[1];
		dpMax[2] = max(temp[1], temp[2]) + input[2];

		temp[0] = dpMin[0];
		temp[1] = dpMin[1];
		temp[2] = dpMin[2];

		dpMin[0] = min(temp[0], temp[1]) + input[0];
		dpMin[1] = min(min(temp[0], temp[1]), temp[2]) + input[1];
		dpMin[2] = min(temp[1], temp[2]) + input[2];
	}

	int resMax = max(max(dpMax[0], dpMax[1]), dpMax[2]);
	int resMin = min(min(dpMin[0], dpMin[1]), dpMin[2]);

	cout << resMax << " " << resMin;

	return 0;
}