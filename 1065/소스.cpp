#include <iostream> 
#include <vector>

using namespace std;

int han(int n)
{
	int count = 0;
	vector <int> arr;
	vector <int> mis;

	for (int i = 1; i <= n; i++)
	{
		int j = 0;

		if (i < 100)
		{
			count++;
		}
		else
		{
			int save = i;

			int count_s = 0;

			while (1)
			{

				arr.push_back(save % 10);

				if (save < 10)
				{
					break;
				}

				save = save / 10;

				j++;
			}

			for (int k = arr.size() - 1; k >= 1; k--)
			{
				mis.push_back(arr.at(k) - arr.at(k - 1));
			}

			if (i < 1000)
			{
				if(mis.at(0) == mis.at(1))
				{
					count++;
				}
			}
			else
			{
				if (mis.at(0) == mis.at(1) && mis.at(1) == mis.at(2))
				{
					count++;
				}
			}
		}
		
		arr.clear();
		mis.clear();
	}

	return count;

}

int main()
{
	int n;
	cin >> n;
	cout << han(n) << endl;
}