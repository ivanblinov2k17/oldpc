#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include "windows.h"
#include <cmath>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

#include "hash_table.h"


int main()
{
	HashTable <string> ht;
	string s1, s2;

	ifstream in("1.txt");

    while (in >> s1)
    {
		getline(in, s2);
		ht.add(s1, s2);
    }
	string s;

	do{
		cin >> s;
		if (s == "0")
			break;
		cout << ht.search(s) << endl;
	}while(true);

	int x;
	cin >> x;
	ht.run(x);
		
	return 0;
}
