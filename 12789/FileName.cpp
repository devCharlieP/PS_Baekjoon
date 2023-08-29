#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define endl '\n'
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector <int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	stack<int> st;

	int num = 1;
	int pt = 0;
	
	for (int i = 0; i < N; i++)
	{
		if(vec[i] == num)
		{
			num++;
			pt = num;
		}
		else if (!st.empty() && st.top() == num)
		{
			i--;
			num++;
			st.pop();
		}
		else
		{
			st.push(vec[i]);
		}
	}

	bool b = true;

	while (!st.empty())
	{
		if (pt != st.top())
		{
			b = false;
			break;
		}

		pt++;
		st.pop();
	}

	if (b == true)
	{
		cout << "Nice";
	}
	else
	{
		cout << "Sad";
	}

	return 0;
}