/* =======================================================
 *  Authors: Christopher Castillo & Cole Shaler
 *  Course: CS271, Spring 2016
 *  Date: March 28, 2016
 *  File: dict.cpp
 * =======================================================*/
using namespace std;


/* =======================================================
 *  Function: empty
 *
 *  Precondition: A Dictionary is initialzed in order to check if it is empty
 *  
 *  Postcondition: A boolean value is returned. True if the Dictionary's count is 0, and false if 
 *  it is greater than 0. 
 * =======================================================*/
template <class KeyType>
bool Dictionary<KeyType>::empty() const
{
	return count == 0;
}
