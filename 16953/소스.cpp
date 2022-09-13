#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#define endl '\n'
using namespace std;

struct AB
{
	long long value;
	long long cnt;
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B;
	cin >> A >> B;

	long long limit = pow(10, 9);

	queue <AB> Q;
	Q.push({A, 0});

	int res = -1;

	while(!Q.empty())
	{
		AB front = Q.front();
		Q.pop();

		if (front.value == B)
		{
			res = front.cnt + 1;
			break;
		}

		if (front.value * 2 <= limit)
		{
			Q.push({ front.value * 2, front.cnt + 1 });
		}

		if (front.value * 10 + 1 <= limit)
		{
			Q.push({ front.value * 10 + 1, front.cnt + 1 });
		}
	}

	cout << res;

	return 0;
}