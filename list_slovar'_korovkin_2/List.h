#ifndef _LIST_H
#define _LIST_H

//#define T int;
template <typename T>
class List
{
	class Cell{
	public:
		T data;
		Cell *link;
	};

	Cell *head;
	size_t size;
	Cell *marker;
	Cell *tail;

public:
	
	template <typename T> List();
	
	template <typename T> List(const List &l);
	
	template <typename T> ~List();
	
	template <typename T> void inc(T x);
	
	template <typename T> size_t getSize() const;
	
	template <typename T> void rewind();
	
	template <typename T> int* getCurrent();
	
	template <typename T> void moveNext();
	
	template <typename T> void print();
};

template <typename T>
List::List()
{
	size = 0;
	head = nullptr;
	marker = head;
	tail = head;
}
template <typename T>
List::List(const List &l)
{
	size = 0;
	head = nullptr;
	if (l.getSize())
	{
		Cell *m = l.head;
		while (m != nullptr)
		{
			inc(m->data);
			m = m->link;
		}
	}
}
template <typename T>
List::~List()
{
	rewind();
	while(marker != nullptr)
	{
		Cell * prev = marker;
		marker = marker->link;
		delete prev;
	}
}
template <typename T>
void List::inc(T x)
{
	Cell *elem = new Cell;
	elem->data = x;
	elem->link = nullptr;
	if (size == 0)
		head = elem;
	else
		tail->link = elem;
	tail = elem;
	size++;
}
template <typename T>
size_t List::getSize() const
{
	return size;
}
template <typename T>
void List::rewind()
{
	marker = head;
}
template <typename T>
T* List::getCurrent()
{
	if (head == nullptr || marker == nullptr)
		return nullptr;
	return &(marker->data);
}
template <typename T>
void List::moveNext()
{
	marker = marker->link;
}
template <typename T>
void printli(List x_li)
{
	x_li.rewind();
	for (size_t i = 0; i < x_li.getSize(); i++)
	{
		cout << *x_li.getCurrent() << endl;
		if (i < x_li.getSize() - 1)
			x_li.moveNext();
	}
}

#endif // !_LIST_;