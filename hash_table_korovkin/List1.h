#pragma once

template<typename T >
class Cell{
public:
	T data1;
	T data2;
	Cell <T> *link;
	Cell <T> *link_back;
	Cell(){}
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
		T & getCurrent1()const{
			if (head == nullptr || position == nullptr)
				throw invalid_argument ("ERRRORRR");
			return (position -> data1);
		}
		T & getCurrent2()const{
			if (head == nullptr || position == nullptr)
				throw invalid_argument ("ERRRORRR");
			return (position -> data2);
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
			Cell <T> *m = l.head;
			while(m != nullptr){
				inc(m->data1, m->data2);
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
	void inc(T x1, T x2){
		Cell <T> *newCell = new Cell <T>;
		newCell ->data1 = x1;
		newCell ->data2 = x2;
		newCell->link = nullptr;
		newCell -> link_back = tail;
		if (size == 0) {
			head = newCell;
		}
		else tail -> link = newCell;
		tail = newCell;
		size++;
	}
	
	size_t getSize()const{return size;}

	T scan(T x, List <T> &l) const{
		List <T> :: Marker m(l);
		m.rewind();
		for( size_t i = 0;i<l.getSize();i++){
			if (m.getCurrent1() == x)
			{
				return m.getCurrent2();
			}
			m.moveNext();
		}
		return "Fail";
	}

};

template<typename T>
void Print(List <T> &l){
	List <T> :: Marker m(l);
	m.rewind();
	for( size_t i = 0;i<l.getSize();i++){
		std::cout<< m.getCurrent1() << " " << m.getCurrent2() << endl;
		m.moveNext();
	}
}