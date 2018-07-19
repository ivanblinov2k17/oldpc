#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	size_t * array = new size_t[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	//------
	size_t max = array[0];
	for (size_t i = 1; i < n; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	cout << max;
	system("pause");
}