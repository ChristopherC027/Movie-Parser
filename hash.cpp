/* =======================================================
 *  Authors: Christopher Castillo & Cole Shaler
 *  Course: CS271, Spring 2016
 *  Date: March 28, 2016
 *  File: hash.cpp
 * =======================================================*/

#include <sstream>
using namespace std;


/* =======================================================
 *  Function: Constructor
 *
 *  Precondition: A HashTable is declared with a specific number of slots determined 
 *  by a integer parameter value.
 *
 *  Postcondition: A HashTable is created with "numSlots" amount of slots that contain 
 *  a list within them. 
 * =======================================================*/
template <class KeyType>
HashTable<KeyType>::HashTable(int numSlots)
{
	table = new List<KeyType>[numSlots];
	slots = numSlots; 
	count = 0; 
}

/* =======================================================
 *  Function: Destructor
 *
 *  Precondition: A HashTable has been initialized. 
 *  
 *  Postcondition: Deletes the table pointer.
 * =======================================================*/
template <class KeyType>
HashTable<KeyType>::~HashTable()
{
	delete [] table;
}

/* =======================================================
 *  Function: get
 *
 *  Precondition: A key of the type KeyType is passed in as a parameter in order to find 
 *  the corresponding value. 
 *  
 *  Postcondition: Either the key's corresponding value is returned or a KeyError is thrown 
 *  meaning that there is no such key in the HashTable. 
 * =======================================================*/
template <class KeyType>
KeyType* HashTable<KeyType>::get(KeyType& k)
{
	int s = k.hash(slots);
	int index = table[s].index(k);
	KeyType *x = table[s][index];
	if (index > -1)
		return x;
	else
		throw KeyError();
}

/* =======================================================
 *  Function: insert
 *
 *  Precondition: A key of the type KeyType is passed in as a parameter in order to insert a 
 *  value in to the HashTable. 
 *  
 *  Postcondition: A value is added to the list of a certain slot calculated by the Hash function.
 * =======================================================*/
template <class KeyType>
void HashTable<KeyType>::insert(KeyType *k)
{
	int s = k->hash(slots);
	table[s].append(k);
	count++;
}

/* =======================================================
 *  Function: remove
 *
 *  Precondition: A key of the type KeyType is passed in as a parameter in order to find the 
 *  corresponding value. 
 *  
 *  Postcondition: Once the value is found the value is removed completely from the HashTable.
 *  If the value is not found, then a Key Error is thrown, which means that no such value exists. 
 * =======================================================*/
template <class KeyType>
void HashTable<KeyType>::remove(KeyType& k)
{
	int s = k.hash(slots); 
	int index = table[s].index(k); 
	if (index > -1)
		table[s].remove(k);
	else
		throw KeyError(); 
	count--; 
}

/* =======================================================
 *  Function: toString
 *
 *  Precondition: A HashTable is initialized. 
 *  
 *  Postcondition: Returns a string representation of the HashTable.
 * =======================================================*/
template <class KeyType>
std::string HashTable<KeyType>::toString(int slot)
{
	std::string str = "{";
	for(int i=0; i < table[slot].length() - 1; i++) {
		std::string result;
		std::ostringstream convert;
		convert<<table[slot][i]<<", ";
		result = convert.str();
		str = str + result;
	}

	if(table[slot].length() != 0) {
		std::string result;
		std::ostringstream convert;
		convert<<table[slot][table[slot].length() - 1];
		result = convert.str();
		str = str + result;
	}
	std::string result;
	std::ostringstream convert;
	convert<<"}";
	result = convert.str();
	str = str + result;
	return str;
}

/* =======================================================
 *  Function: << operator
 *
 *  Precondition: A HashTable is initialized.
 *  
 *  Postcondition: Allows the ostream operator to print our a string representation of a 
 *  HashTable. 
 * =======================================================*/
template <class KeyType>
std::ostream& operator<<(std::ostream& os, const HashTable<KeyType>& hash)
{

	std::stringstream ss;
	
	bool first = true; 
	ss << "{";
	for (int slot = 0; slot < hash.slots; slot++)
	{
		for (int index = 0; index < hash.table[slot].length(); index++)
		{
			if (first){
				first = false;
			}
			else{
				ss << ", ";
			}
			ss << hash.table[slot][index];
		}
	}
	ss << "}";
	
	os << ss.str();
	return os;
}
