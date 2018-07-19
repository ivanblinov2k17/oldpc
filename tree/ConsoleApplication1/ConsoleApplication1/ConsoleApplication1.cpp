#include "stdafx.h"
#include <iostream>

using namespace std;

#include "Node.h"
#include "Tree.h"

int main()
{
	Tree tr;

	tr.add(12);
	tr.add(17);
	tr.add(6);
	tr.add(3);
	tr.add(25);
	tr.add(13);
	tr.add(66);
	tr.add(15);
	tr.print();
	cout << endl;
	/*
	for (int i = 1; i < 68; i++)
	{
		cout << i << " ";
		Node* cell = tr.search(i);
		if(cell != nullptr)
			cout << cell->value << endl;
		else cout << "Net";
		cout << endl;
	}
	*/
	//tr.insertafter(5, 6);

	Tree::iterator i = tr.newiter();
	i.print();
	++i;
	i.print();
	--i;
	i.print();
	i^2;
	i.print();

	cout << endl;
	
	return 0;
}