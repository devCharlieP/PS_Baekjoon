#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

struct student
{
	string name;
	int korean;
	int english;
	int math;
};

bool cmp(const student &s1, const student &s2)
{
	if (s1.korean == s2.korean && s1.english == s2.english && s1.math == s2.math)
	{
		return s1.name < s2.name;
	}
	else if (s1.korean == s2.korean && s1.english == s2.english)
	{
		return s1.math > s2.math;
	}
	else if (s1.korean == s2.korean)
	{
		return s1.english < s2.english;
	}
	else
	{
		return s1.korean > s2.korean;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<student> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].name >> vec[i].korean >> vec[i].english >> vec[i].math;
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].name << endl;
	}

	return 0;
}