#include "BinTrees.h"


int main()
{
	BinaryTree<int> IntBinTree;
	IntBinTree.add_item(1);
	IntBinTree.add_item(3);
	IntBinTree.add_item(5);
	IntBinTree.traverse();
	int value = 0;
	if (IntBinTree.find_item(5, value))
		cout << "Found: " << value << endl;

	//
	BinaryTree<Person> PersonTree;
	Person p1("Ivan", "Ivanoff", 1);
	Person p2("Marshall", "Mathers", 3);
	Person p3("Satan", "Lucifyre", 666);
	PersonTree.add_item(p3);
	PersonTree.add_item(p1);
	PersonTree.add_item(p2);
	Person searchResult;
	if (PersonTree.find_item(Person("Mathers"), searchResult))
		searchResult.print();
	else
		cout << "Person not found" << endl;

	system("pause");
	return 0;
}