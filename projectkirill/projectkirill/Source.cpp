#include <iostream>
#include <vector>
#include <string>
#include "Header.h"
using namespace std;
class String
{
private:
	unsigned int len;
	vector<char> myvec;
public:
	String()
	{
		len = 0;
		myvec.resize(len);
	}
	String(string s)
	{
		len = s.length();
		myvec.resize(len);
		for (int i = 0; i < len; i++)
		{
			myvec[i] = s[i];
		}
	}
	String(int n)
	{
		len = n;
		myvec.resize(len);
		for (int i = 0; i < len; i++)
		{
			myvec[i] = '.';
		}
	}
	void change(int n, char c)
	{
		myvec[n] = c;
	}
	char pick_var(int n)
	{
		return myvec[n];
	}
	char operator[] (int n)
	{
		return myvec[n];
	}
};
int main()
{
	
}