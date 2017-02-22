/* =======================================================
 *  Authors: Christopher Castillo & Cole Shaler
 *  Course: CS271, Spring 2016
 *  Date: March 28, 2016
 *  File: hash.h
 * =======================================================*/

#ifndef HASH_H
#define HASH_H

#include "list.h"

template <class KeyType>
class HashTable;

template <class KeyType>
std::ostream& operator<<(std::ostream& os, const HashTable<KeyType>& hash);

template <class KeyType>
class HashTable
{
	public:
		HashTable(int numSlots);
		~HashTable();

		KeyType* get(KeyType& k);
		void insert(KeyType *k);
		void remove(KeyType& k);

		std::string toString(int slot);

	protected:
		int count; 
		int slots;
		List<KeyType> *table;  // an array of List<KeyType*>'s

		friend std::ostream& operator<< <KeyType>(std::ostream& os, const HashTable<KeyType>& hash);
};

class KeyError { };

#include "hash.cpp"

#endif
