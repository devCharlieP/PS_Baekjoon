#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int S, M, L, XL, XXL, XXXL;
	cin >> S >> M >> L >> XL >> XXL >> XXXL;

	int T, P;
	cin >> T >> P;

	cout << ((S + T - 1) / T) + ((M + T - 1) / T) + ((L + T - 1) / T) + ((XL + T - 1) / T) + ((XXL + T - 1) / T) + ((XXXL + T - 1) / T) << endl;
	cout << N / P << " " << N % P;

	return 0;
}