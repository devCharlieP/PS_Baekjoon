#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'
using namespace std;
int N;

void rec(int n)
{
	if (n == N)
	{
		for (int i = 0; i < n * 4; i++)
			cout << "_";
		cout << "\"����Լ��� ������?\"" << endl;

		for (int i = 0; i < n * 4; i++)
			cout << "_";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;

		for (int i = 0; i < n * 4; i++)
			cout << "_";
		cout << "��� �亯�Ͽ���." << endl;

		return;
	}
	else
	{
		for (int i = 0; i < n * 4; i++)
			cout << "_";
		cout << "\"����Լ��� ������?\"" << endl;

		for (int i = 0; i < n * 4; i++)
			cout << "_";
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;

		for (int i = 0; i < n * 4; i++)
			cout << "_";
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;

		for (int i = 0; i < n * 4; i++)
			cout << "_";
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;
		

		rec(n + 1);

		for (int i = 0; i < n * 4; i++)
			cout << "_";
		cout << "��� �亯�Ͽ���." << endl;
	}
	
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;	

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;

	rec(0);

	return 0;
}