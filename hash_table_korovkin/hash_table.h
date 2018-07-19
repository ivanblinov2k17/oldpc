#pragma once
#include "List1.h"

template <typename T> unsigned long simpleHashFunc( T q ) 
{
	T * pobj = &q;
	unsigned long res = 0; 
	if (typeid(q).name() == typeid(string).name())
		return res  = q.length();
	unsigned char *pbyte = (unsigned char *)pobj; 
	for (size_t k = 0; k < sizeof(T); k++) 
	{ 
		res+=*pbyte; 
		pbyte++; 
	}
	return res; 
}


template <typename T>class HashTable{
public:
	size_t n;
	List <T> *m;

	template <typename T> struct iterator{
		Cell <T> *ptr;
		iterator(Cell<T> *p) : ptr(p){}
		bool operator !=(iterator<T> z) { return ptr != z.ptr;}
		void operator =(iterator<T> z) { ptr = z.ptr;}
		void operator ++() {ptr = ptr->link;}
		T& operator*() {return ptr.data1;}
	};
	iterator<T> end() {return nullptr;}
	iterator<T> begin() {return m[0].head;}
	iterator<T> set(int i) {return m[i].head;}

	void run(int x){
		iterator <T> i = set(x);
		for (i; i != end(); ++i)
			cout << i.ptr->data1 << endl;
	}

	HashTable()
	{
		n = 256;
		m = new List <T> [n];
	}

	~HashTable()
	{
		delete [] m;
	}

	void add(T x1, T x2){
		//cout << simpleHashFunc(x1)%n << endl;
		m[simpleHashFunc(x1)%n].inc(x1,x2);
	}

	T search (T x1){
		size_t tmp = simpleHashFunc(x1)%n;
		T res = m[tmp].scan(x1, m[tmp]);
		return res;
	}

	long check(int k)
	{
		long res = 0;
		for (long i = 0; i < n; i++)
		{
			if (m[i].getSize() > k)
				res++;
		}
		return res;
	}
};