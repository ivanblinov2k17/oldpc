#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	double temp;
	int ans;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		ans = int(round((temp - 32) * 5 / 9));
		cout << ans << endl;
	}
	return 0;
}