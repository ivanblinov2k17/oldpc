#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	double x, y, z;
	cin >> x >> y >> z;
	double ans=3 * x*x + 3 * y*y + 3 * z*z + 2 * x*y - 2 * x*z - 2 * y*z -2.4;
	cout << ans;
	system("pause");
}