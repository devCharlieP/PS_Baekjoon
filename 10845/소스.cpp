#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

vector <int> Q;

void push(int num_push)
{
	Q.push_back(num_push);
}

int pop()
{
	if (Q.size() == 0)
	{
		return -1;
	}

	int num_pop = Q[0];

	Q.erase(Q.begin());

	return num_pop;
}

int size()
{
	return Q.size();
}

int empty()
{
	if (Q.size() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int front()
{
	if (Q.size() == 0)
	{
		return -1;
	}

	return Q[0];
}

int back()
{
	if (Q.size() == 0)
	{
		return -1;
	}

	return Q[Q.size() - 1];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int num_push;
			cin >> num_push;
			push(num_push);
		}
		else if (s == "pop")
		{
			cout << pop() << endl;
		}
		else if (s == "size")
		{
			cout << size() << endl;
		}
		else if (s == "empty")
		{
			cout << empty() << endl;
		}
		else if (s == "front")
		{
			cout << front() << endl;
		}
		else if (s == "back")
		{
			cout << back() << endl;
		}
	}

	return 0;
}