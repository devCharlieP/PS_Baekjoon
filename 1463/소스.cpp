#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//int vec[1000001];
//
//int dp(int n)
//{
//	if (n == 1)
//	{
//		return 0;
//	}
//
//
//	if (vec[n] > 0)
//	{
//		return vec[n];
//	}
//
//	vec[n] = dp(n - 1) + 1;
//
//	if (n % 2 == 0)
//	{
//		int temp = dp(n / 2) + 1;
//
//		if (vec[n] > temp)
//		{
//			vec[n] = temp;
//		}
//	}
//
//	if (n % 3 == 0)
//	{
//		int temp = dp(n / 3) + 1;
//
//		if (vec[n] > temp)
//		{
//			vec[n] = temp;
//		}
//	}
//
//	return vec[n];
//
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//
//	cout << dp(n);
//
//	return 0;
//}