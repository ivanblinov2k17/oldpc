#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <cmath>
#include <fstream>
#include <string>

#include "List1.h"

using namespace std;

template<typename T>
void sort(List <T> &l)
{
	size_t n = l.getSize();
	List <T> :: Marker m1(l);
	List <T> :: Marker m2(l);
	m1.rewind();
	m2.rewind();
	if (m1.canMoveNext())
		m1.moveNext();
	size_t j = 0;
	for (size_t i = 0; i < l.getSize(); i++)
	{
		try{
			if (m1.getCurrent() < m2.getCurrent())
			{
				List <T> :: Marker m3(l);
				m3.position = m1.position;
				T temp = m3.getCurrent();
				while(true)
				{
					m1.getCurrent() = m2.getCurrent();
					if (m2.position == l.head) break;
					if (temp > m2.getCurrent()) break;
					m1.moveBack();
					m2.moveBack();
				}
				m2.getCurrent() = temp;
				m1.position = m3.position;
				m2.position = m1.position;
				m2.moveBack();
			}
			if (m1.canMoveNext()) m1.moveNext();
			if (m2.canMoveNext()) m2.moveNext();
		}
		catch(invalid_argument &q)
		{
			cout << q.what();
		}
		cout << i*100/n << "%" << endl;
	}
}

void test(){
	List <int> li;
	li.inc(2);
	li.inc(6);
	li.inc(1);
	li.inc(9);

	List <int> :: Marker m1(li);
	List <int> :: Marker m2(li);

	Print(li);

	cout << endl;

	m1.rewind();
	m2.rewind();

	m2.moveNext();
	m2.moveNext();

	li.swap(m1,m2);

	Print(li);
}

void test2()
{
	
	List <string> li;
	string s;
	string temp="1.txt";
	ifstream in(temp);

	cout << "Reading... ";

    while (getline(in, s))
    {
		li.inc(s);
    }

	//считал из файла

	sort(li);

	//отсортировали
	temp = "output.txt";
	ofstream output(temp);
	List <string>:: Marker m(li);
	m.rewind();
	for( int i = 0; i<li.getSize(); i++){
		output << m.getCurrent() << '\n';
		m.moveNext();
	}
}

void test3()
{
	List <int> li;
	li.inc(2);
	li.inc(6);
	li.inc(1);
	li.inc(9);
	Print(li);
	cout << endl;
	li.del(2);
	Print(li);
}

void test4()
{
	List <int> li;
	li.inc(2);
	li.inc(6);
	li.inc(1);
	li.inc(9);
	Print(li);
	cout << endl;
	li.insertafter(18, 2); //18 после 2
	Print(li);
}

int main()
{
	test4();
	return 0;
}
