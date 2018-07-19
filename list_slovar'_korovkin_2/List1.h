
#include<iostream>
template<typename T >
class Cell{
public:
	T data;
	Cell <T> *link;
	Cell <T> *link_back;
	Cell(){}
	Cell(T x):data(x){}
	~Cell(){}
};

template<typename T >
class List{

	size_t size;
	Cell <T> *tail; 

public:
	Cell <T> *head;
	class Marker{
	public:
		Cell <T> * head;
		Marker(const List &l) {head = l.head;}
		Cell <T> *position;
		void moveNext(){
			if (position->link != nullptr) position = position -> link;
		}
		void moveBack(){
			if (position->link_back != nullptr) position = position -> link_back;
		}
		void rewind(){
			position = head;
		}
		bool canMoveNext(){
			if (position -> link != nullptr) return true;
			else return false;
		}
		T & getCurrent()const{
			if (head == nullptr || position == nullptr)
				throw invalid_argument ("ERRRORRR");
			return (position -> data);
		}
	};
	
	List():head(nullptr),size(0),tail(nullptr){}
	List(size_t s,T default_val){
		for(size_t i = 0;i<s;i++){
			inc(default_val);
		}
	}
	List(const List&l){
		size = 0;
		head = nullptr;
		tail = nullptr;
		if(l.size){
			Cell *m = l.head;
			while(m != nullptr){
				inc(m->data);
				m = m->link;
			}
		}
	}

	~List(){
		Cell <T> * marker = head;
		while(marker != nullptr){
			Cell <T> *elem = marker;
			marker =  marker->link;
			delete elem;
		}
	}
	void inc(T x){
		Cell <T> *newCell = new Cell <T>;
		newCell ->data = x;
		newCell->link = nullptr;
		newCell -> link_back = tail;
		if (size == 0) {
			head = newCell;
		}
		else tail -> link = newCell;
		tail = newCell;
		size++;
	}

	void del(T x)
	{
		Marker m(*this);
		m.rewind();
		while(true)
		{
			if (x == m.getCurrent())
			{
				size--;
				if (m.position == head)
				{
					m.moveNext();
					delete head;
					head = m.position;
					return;
				}
				if (m.position == tail)
				{
					m.moveBack();
					delete tail;
					tail = m.position;
					return;
				}
				m.position->link_back->link = m.position->link;
				m.position->link->link_back = m.position->link_back;
				return;
			}
			if (m.position == tail)
			{
				cout << "Error" << endl;
				return;
			}
			m.moveNext();
		}
	}

	void insertafter(T x, T y) // вставить х псле y
	{
		Marker m(*this);
		m.rewind();
		while(true)
		{
			if (y == m.getCurrent())
			{
				size++;
				if (m.position == tail)
				{
					inc(x);
					return;
				}
				Cell <T> *newCell = new Cell <T>;
				newCell->data = x;
				newCell->link = m.position->link;
				newCell->link_back = m.position;
				m.position->link = newCell;
				return;
			}
			if (m.position == tail)
			{
				cout << "Error" << endl;
				return;
			}
			m.moveNext();
		}
	}
	
	size_t getSize()const{return size;}

	void swap(Marker m1, Marker m2)
	{
		T temp = m1.getCurrent();
		m1.getCurrent() = m2.getCurrent();
		m2.getCurrent() = temp;

	}
};

template<typename T>
void Print(List <T> &l){
	List <T> :: Marker m(l);
	m.rewind();
	for( size_t i = 0;i<l.getSize();i++){
		std::cout<< m.getCurrent() <<"\n";
		m.moveNext();
	}
}
