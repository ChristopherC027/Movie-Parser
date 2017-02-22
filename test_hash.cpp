/* =======================================================
 *  Authors: Christopher Castillo & Cole Shaler
 *  Course: CS271, Spring 2016
 *  Date: March 28, 2016
 *  File: test_hash.cpp
 * =======================================================*/

#include "hash.h" 
#include <iostream>
#include <cassert> 
using namespace std;

class Test
{
	public:
		Test(int KeyValue);
		int hash(int slots) {return key % slots;}
		bool operator!=(const Test& otherTest) {return (key != otherTest.key);}	
		bool operator==(const Test& otherTest) {return (key == otherTest.key);}
		int key;
		friend std::ostream& operator<< (std::ostream& os, const Test& t) {os << t.key;  return os;}
};

Test::Test(int KeyValue)
{
	key = KeyValue;
}

void testConstructor()
{
	HashTable<Test> h(5);
}

void testInsert()
{
	HashTable<Test> h(5); 
	Test t(5);
	Test *r = &t; 
	h.insert(r); 
	Test q(10);
	r = &q; 
	h.insert(r);
	assert(h.toString(0) == "{5, 10}"); 
}

void testGet()
{
	HashTable<Test> h(5); 
	Test t(5); 
	Test *r = &t; 
	h.insert(r); 
	h.get(*r); 
	try
	{
		assert(*(h.get(*r)) == 5);
	}
	catch (KeyError exception)
	{
		cerr<<"Error: Key does not exist. Cannot get."<<endl;
	}
}

void testRemove()
{
	HashTable<Test> h(5); 
	Test t(5); 
	Test *r = &t; 
	h.insert(r);
	h.remove(*r); 
	try
	{
		assert(h.toString(0) == "{}"); 
	}
	catch (KeyError exception)
	{
		cerr<<"Error: Key does not exist. Cannot remove."<< endl; 
	}
}

int main()
{
	 
	testConstructor(); 
	testInsert(); 
	testGet();
	testRemove();  
	return 0;
}
