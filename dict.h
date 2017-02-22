/* =======================================================
 *  Authors: Christopher Castillo & Cole Shaler
 *  Course: CS271, Spring 2016
 *  Date: March 28, 2016
 *  File: dict.h
 * =======================================================*/

#ifndef _DICT_H
#define _DICT_H

#include "hash.h"

template <class KeyType>
class Dictionary: public HashTable<KeyType>
{
	public: 
		Dictionary(int numslots)
		: HashTable<KeyType>(numslots) {};

		bool empty() const;

	//private: 
		int slots;
		int count;
};

#include "dict.cpp"

#endif


