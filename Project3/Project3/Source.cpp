#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	List<int>::Iterator it;
	List<int>* intLst = new List<int>;
	int N = 7;
	int M = 2;
	int k = 1;

	for (int i = 1; i <= N; ++i)
		intLst->push_back(i);

	it = intLst->begin();
	do
	{
		if (k%M == 0)
		{
			k = 0;
			cout << "Removed " << *it << endl;
			intLst->remove(it);
		}
		++k;
		if (it + 1 != intLst->end())
			++it;
	} while (intLst->begin() + 1 != intLst->end());
	cout << "last: " << *it << endl;

	/*for (it = intLst->begin();it!=intLst->end();++it)
	cout << *it << endl;*/

	/*while (intLst->pop_front(x))
	{
	cout << x << endl;
	}*/
	delete intLst;
	system("pause");
	return 0;
}