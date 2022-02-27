#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

vector <int> D;

void push_front(int front)
{
	D.push_back(front);

	for (int i = D.size() - 1; i > 0; i--)
	{
		swap(D[i], D[i - 1]);
	}
}

void push_back(int back)
{
	D.push_back(back);
}

int pop_front()
{
	if (D.size() == 0)
	{
		return -1;
	}

	int front = D[0];
	D.erase(D.begin());

	return front;
}

int pop_back()
{
	if (D.size() == 0)
	{
		return -1;
	}

	int back = D[D.size() - 1];
	D.pop_back();

	return back;
}

int size()
{
	return D.size();
}

int empty()
{
	if (D.size() == 0)
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
	if (D.size() == 0)
	{
		return -1;
	}

	return D[0];
}

int back()
{
	if (D.size() == 0)
	{
		return -1;
	}

	return D[D.size() - 1];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	string s;

	for (int i = 1; i <= N; i++)
	{
		cin >> s;

		if (s == "push_front")
		{
			int front;
			cin >> front;
			push_front(front);
		}
		else if (s == "push_back")
		{
			int back;
			cin >> back;
			push_back(back);
		}
		else if (s == "pop_front")
		{
			cout << pop_front() << endl;
		}
		else if (s == "pop_back")
		{
			cout << pop_back() << endl;
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