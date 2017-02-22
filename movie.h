/* =======================================================
 *  Authors: Christopher Castillo & Cole Shaler
 *  Course: CS271, Spring 2016
 *  Date: March 28, 2016
 *  File: movie.h
 * =======================================================*/

#ifndef _MOVIE_H
#define _MOVIE_H

#include "list.h"
#include <iostream>
#include <sstream>

class Movie
{
	public:
		Movie(string xtitle="", string xcast="") {title = xtitle; cast = xcast;}
 
		int hash(int slots)
		{
			int length = title.length(), val = 0;
			for(int i = 0; i < length; i++) {
				val = title[i] * title[i] + val * 19;
			}
			val = ((val % slots) + slots) % slots;		//converts val to positive value if negative, does nothing if positive
			return val;
		}
		Movie& operator=(const Movie& otherMovie) {title = otherMovie.title; cast = otherMovie.cast; return *this;}
			
		bool operator==(const Movie& otherMovie) {return (title == otherMovie.title);}
		bool operator!=(const Movie& otherMovie) {return !(*this == otherMovie);}

		friend std::ostream& operator<< (std::ostream& os, Movie& m) {os << m.cast<<endl; return os;}

		string title;
		string cast; 
};

#endif

