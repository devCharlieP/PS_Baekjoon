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

	int N, k;
	cin >> N >> k;

	vector <int> score(N);
	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
	}

	sort(score.begin(), score.end());

	cout << score[N - k];

	return 0;
}