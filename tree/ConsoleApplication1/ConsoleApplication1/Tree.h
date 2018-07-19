#pragma once
class Tree
{
public:
	Node* first;
	size_t size;

	class iterator
	{
		Node* position;
	public:
		iterator() {position = nullptr;}
		iterator(Node* p) {position = p;}
		void operator ++() {if (position->right != nullptr) position = position->right;}
		void operator --() {if (position->left != nullptr) position = position->left;}
		void operator ^(int i) {
			for (int j = 0; j < i; j++)
				if (position->back != nullptr) position = position->back;
		}
		void print(){cout << position->data << endl;}
	};
	iterator newiter()
	{
		iterator* i = new iterator(first);
		return *i;
	}

	Tree()
	{
		size = 0;
		first = nullptr;
	}

	~Tree()
	{
		if (size > 0) destroy(first);
	}

	void add(int x)
	{
		insert(x, first);
		cout << x << " added" << endl;
	}
	void print()
	{
		print(first);
	}

	Node* search(int x)
	{
		Node* res = nullptr;
		res = search(x, first);
		return res;
	}

	void insertafter(int x, int y) // x вставляем после y
	{
		Node* cell = search(y);
		if (cell == nullptr)
		{
			cout << "error" << endl;
			return;
		}
		Node* newNode = new Node (x);
		if (x < y)
		{
			if (cell->left != nullptr)
			{
				cell->left->back = newNode;
				if (cell->left->data > x)
				{
					newNode->right = cell->left;
				}
				else if (cell->left->data < x)
				{
					newNode->left = cell->left;
				}
				else return;
			}
			cell->left = newNode;
		}
		else if (x > y)
		{
			if (cell->right != nullptr)
			{
				cell->right->back = newNode;
				if (cell->right->data > x)
				{
					newNode->right = cell->right;
				}
				else if (cell->right->data < x)
				{
					newNode->left = cell->right;
				}
				else return;
			}
			cell->right = newNode;
		}
	}

	void deleteelem(int x)
	{
	}

private:

	Node* search(int x, Node* cell)
	{
		if (cell->data == x)
			return cell;
		else if (x > cell->data)
		{
			if (cell->right == nullptr)
				return nullptr;
			cell = cell->right;
			search(x, cell);
		}
		else if (x < cell->data)
		{
			if (cell->left == nullptr)
				return nullptr;
			cell = cell->left;
			search(x, cell);
		}
	}

	void destroy (Node* cell)
	{
		if (cell != nullptr)
		{
			destroy(cell->left);
			destroy(cell->right);
			delete cell; 
		}
	}

	void print(Node* marker)
	{
		if (marker->left != nullptr) print(marker->left);
		cout << marker->data << " ";
		if (marker->right != nullptr) print(marker->right);
	}

	void insert(int x, Node* marker)
	{
		if (size == 0)
		{
			Node* newNode = new Node(x);
			first = newNode;
			size++;
			return;
		}
		if (marker->data == x)
			return;
		if (x < marker->data)
		{
			if (marker->left == nullptr)
			{
				Node* newNode = new Node(x);
				marker->left = newNode;
				newNode->back = marker;
				size++;
				return;
			}
			marker = marker->left;
		}
		else if (x > marker->data)
		{
			if (marker->right == nullptr)
			{
				Node* newNode = new Node(x);
				marker->right = newNode;
				newNode->back = marker;
				newNode->left = newNode->right = nullptr;
				size++;
				return;
			}
			marker = marker->right;
		}
		insert(x, marker);
	}
};