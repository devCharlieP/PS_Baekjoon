#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, B;
	cin >> N >> B;

	vector<int> res;
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	while (N >= B)
	{
		res.push_back(N % B);
		N /= B;
	}

	res.push_back(N);

	for (int i = res.size() - 1; i >= 0; i--)
	{
		if (res[i] <= 9)
		{
			cout << res[i];
		}
		else
		{
			cout << str[res[i] - 10];
		}
	}

	return 0;
}