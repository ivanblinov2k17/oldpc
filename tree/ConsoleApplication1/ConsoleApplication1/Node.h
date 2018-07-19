#pragma once
class Node
{
public:
	int data;
	Node* right;
	Node* left;
	Node* back;
	int value;
	Node()
	{
		data = value = 0;
		right = left = back = nullptr;
	}

	Node(int x)
	{
		data = x;
		right = left = back = nullptr;
		value = 0;
	}

	~Node()
	{
	}
	
	void del(Node* cell)
	{
		if (cell != nullptr)
		{
			del(cell->left);
			del(cell->right);
			delete cell; 
		}
	}
};