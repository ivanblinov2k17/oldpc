template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node(T& _data) :data(_data), next(nullptr) {}
};

template<typename T>
class List
{
private:
	Node<T>* first;
	Node<T>* last;
	int size;
public:
	List() :size(0), first(nullptr), last(nullptr) {}
	~List();
	class Iterator;

	Iterator begin() { return Iterator(first); }
	Iterator end() { return Iterator(last->next); }

	void push_back(T& elem);
	void push_front(T& elem);
	bool pop_back(T& elem);
	bool pop_front(T& elem);

	
	bool remove(Iterator it);
	bool insert(Iterator it);
	class Iterator
	{
	private:
		Node<T>* ptr;
	public:
		Iterator() :ptr(nullptr) {}
		Iterator(Node<T>* _ptr) :ptr(_ptr) {}
		Iterator& operator++() {
			ptr = ptr->next;
			return *this;
		}
		Iterator operator++(int) {
			Iterator it(ptr);
			ptr = ptr->next;
			return it;
		}
		Iterator operator+(int n) {
			Iterator it(ptr);
			for (int i = 0; i<n; ++i)
				++it;
			return it;
		}
		bool operator==(Iterator it) const { return ptr == it.ptr; }
		bool operator!=(Iterator it) const { return ptr != it.ptr; }
		T& operator*() const { return ptr->data; }
		Node<T>* getptr() { return ptr; }
		friend class List<T>;
	};


};

template<typename T>
void List<T>::push_back(T& elem)
{
	if (size == 0)
	{
		first = new Node<T>(elem);
		last = first;
		++size;
		return;
	}

	Node<T>* tmp = new Node<T>(elem);
	last->next = tmp;
	last = tmp;
	++size;
}

template<typename T>
void List<T>::push_front(T& elem)
{
	if (size == 0)
	{
		first = new Node<T>(elem);
		last = first;
		++size;
		return;
	}

	Node<T>* tmp = new Node<T>(elem);
	tmp->next = first;
	first = tmp;
	++size;
}

template<typename T>
bool List<T>::pop_back(T& elem)
{
	if (size == 0)
		return false;
	if (size == 1)
	{
		elem = first->data;
		delete first;
		size = 0;
		return true;
	}

	Node<T>* beforeLast = first;
	while (beforeLast->next != last)
	{
		beforeLast = beforeLast->next;
	}
	elem = last->data;
	delete last;
	beforeLast->next = nullptr;
	last = beforeLast;
	--size;
	return true;
}

template<typename T>
bool List<T>::pop_front(T& elem)
{
	if (size == 0)
		return false;
	if (size == 1)
	{
		elem = first->data;
		delete first;
		size = 0;
		return true;
	}

	Node<T>* firstNext = first->next;
	elem = first->data;
	delete first;
	first = firstNext;
	--size;
	return true;
}

template<typename T>
List<T>::~List()
{
	if (size > 0)
		do
		{
			Node<T>* tmp = first;
			first = first->next;
			delete tmp;
		} while (first != nullptr);
}

template<typename T>
bool List<T>::remove(Iterator it)
{
	Iterator curr(first);
	while (curr != end())
	{
		//Iterator prev = curr++;
		if (curr == it)
		{
			Node<T>* next = curr.ptr->next;
			curr.ptr->next = curr.ptr->next->next;
			delete next;
			return true;
		}
	}
	return false;
}
template<typename T>
bool List<T>::insert(Iterator it)
{
	Node<T>* next = it.getptr()->next();
}
