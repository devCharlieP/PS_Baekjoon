#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector <int> add(vector <int> vec, int x)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == x)
		{
			return vec;
		}
	}

	vec.push_back(x);
	return vec;
}

vector <int> remove(vector <int> vec, int x)
{
	int idx = -1;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == x)
		{
			idx = i;
			break;
		}
	}

	if (idx == -1)
	{
		return vec;
	}
	else
	{
		vec.erase(vec.begin() + idx);
		return vec;
	}
}

void check(vector <int> vec, int x)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == x)
		{
			
			cout << "1\n";
			return;
		}
	}

	cout << "0\n";
}

vector <int> toggle(vector <int> vec, int x)
{

	int idx = -1;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == x)
		{
			idx = i;
			break;
		}
	}

	if (idx == -1)
	{
		vec.push_back(x);
		return vec;
	}
	else
	{
		vec.erase(vec.begin() + idx);
		return vec;
	}
}

vector <int> all()
{
	vector <int> all;

	for (int i = 0; i < 20; i++)
	{
		all.push_back(i + 1);
	}

	return all;
}

vector <int> empty()
{
	vector <int> empty;

	return empty;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector <int> vec;
	vector <int> out;

	for (int i = 0; i < n; i++)
	{
		string str;
		
		cin >> str;

		if (str == "add")
		{
			int x;
			cin >> x;

			vec = add(vec, x);
		}
		else if (str == "remove")
		{
			int x;
			cin >> x;

			vec = remove(vec, x);
		}
		else if (str == "check")
		{
			int x;
			cin >> x;

			check(vec, x);
		}
		else if (str == "toggle")
		{
			int x;
			cin >> x;

			vec = toggle(vec, x);
		}
		else if (str == "all")
		{
			vec = all();
		}
		else if (str == "empty")
		{
			vec = empty();
		}
	}

	return 0;
}