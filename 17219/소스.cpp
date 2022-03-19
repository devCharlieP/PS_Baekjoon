#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;
#define endl "\n"

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	map<string, string> site_pw;

	for (int i = 1; i <= N; i++)
	{
		string site;
		cin >> site;

		string pw;
		cin >> pw;

		site_pw.insert({ site, pw });
	}

	for (int i = 1; i <= M; i++)
	{
		string site_f;
		cin >> site_f;

		auto iter = site_pw.find(site_f);
		cout << iter->second << endl;
	}

	return 0;
}