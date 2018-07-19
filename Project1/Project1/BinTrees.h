#include <iostream>
#include <string>
using namespace std;

struct Person
{
	string Name;
	string Surname;
	int id;
	Person(string _Name, string _Surname, int _id) :Name(_Name),
		Surname(_Surname),
		id(_id) {}
	Person(string _Surname) :Surname(_Surname) {}
	Person() {}

	void print() const
	{
		cout << Name << " " << Surname << " " << id << endl;
	}

	bool operator==(const Person& pers) const
	{
		return pers.Surname == Surname;
	}
	bool operator<(const Person& pers) const
	{
		return pers.Surname < Surname;
	}
};

template<typename T>
struct TreeNode
{
	T data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(T item) : data(item),
		left(nullptr),
		right(nullptr) {}
};

template<typename T>
class BinaryTree
{
private:
	TreeNode<T>* root;
	int size;
	//Добавление элемента в поддерево
	void add_item_subtree(const T&, TreeNode<T>*);
	//Удаление поддерева (для деструктора)
	void delete_subtree(TreeNode<T>*);
	//Поиск элемента в поддереве
	bool find_item_subtree(const T&, T&, TreeNode<T>*) const;
	//Обход поддерева
	void traverse_subtree(TreeNode<T>*) const;
	//Поиск минимального элемента
	TreeNode<T>* find_minimum(TreeNode<T>*) const;
public:
	BinaryTree() : root(nullptr), size(0) {}
	~BinaryTree();
	//Вставка элемента в дерево
	void add_item(const T&);
	//Обход дерева
	void traverse() const;
	//Поиск элемента
	bool find_item(const T&, T&) const;
	//Удаление элемента
	bool delete_elem(const T&);
};

//Деструктор
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	//Дерево пустое
	if (size == 0) return;
	delete_subtree(root);
}

//Удаление поддерева
template<typename T>
void BinaryTree<T>::delete_subtree(TreeNode<T>* subroot)
{
	if (subroot->left != nullptr)
		delete_subtree(subroot->left);
	if (subroot->right != nullptr)
		delete_subtree(subroot->right);

	delete subroot;
}

//Добавление элемента
template<typename T>
void BinaryTree<T>::add_item(const T& item)
{
	if (size == 0)
	{
		root = new TreeNode<T>(item);
		++size;
		return;
	}
	//Добавление элемента в поддерево корня
	add_item_subtree(item, root);
	++size;
}

//Добавление элемента в поддерево
template<typename T>
void BinaryTree<T>::add_item_subtree(const T& item,
	TreeNode<T>* subroot)
{
	//Нужно добавлять в левое поддерево
	if (item < subroot->data)
	{
		//Левое поддерево пусто, создаем новый узел
		if (subroot->left == nullptr)
		{
			subroot->left = new TreeNode<T>(item);
			++size;
			return;
		}
		//Левое дерево непусто, продолжаем поиск
		add_item_subtree(item, subroot->left);
	}
	else //Нужно добавлять в правое поддерево
	{
		//Правое поддерево пусто, создаем новый узел
		if (subroot->right == nullptr)
		{
			subroot->right = new TreeNode<T>(item);
			++size;
			return;
		}
		//Правое дерево непусто, продолжаем поиск
		add_item_subtree(item, subroot->right);
	}
}

//Обход дерева
template<typename T>
void BinaryTree<T>::traverse() const
{
	if (size == 0) return;
	traverse_subtree(root);
}

//Обход поддерева
template<typename T>
void BinaryTree<T>::traverse_subtree(TreeNode<T>* subroot) const
{
	if (subroot->left != nullptr)
		traverse_subtree(subroot->left);
	cout << subroot->data << endl;
	if (subroot->right != nullptr)
		traverse_subtree(subroot->right);
}

//Поиск во всем дереве
template<typename T>
bool BinaryTree<T>::find_item(const T& key,
	T& value) const
{
	if (size == 0) return false;
	return find_item_subtree(key, value, root);
}

//Поиск в поддереве
template<typename T>
bool BinaryTree<T>::find_item_subtree(const T& key,
	T& value,
	TreeNode<T>* subroot) const
{
	if (subroot->data == key)
	{
		value = subroot->data;
		return true;
	}

	//Нужно искать в левом поддереве
	if (key < subroot->data)
	{
		if (subroot->left == nullptr)
			return false;
		return find_item_subtree(key, value, subroot->left);
	}
	else //Нужно искать в правом поддереве
	{
		if (subroot->right == nullptr)
			return false;
		return find_item_subtree(key, value, subroot->right);
	}

}