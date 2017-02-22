/* =======================================================
 *  Authors: Christopher Castillo & Cole Shaler
 *  Course: CS271, Spring 2016
 *  Date: March 28, 2016
 *  File: query_movies.cpp
 * =======================================================*/

#include "dict.h"
#include "movie.h" 
#include "list.h" 
#include <iostream>
#include <fstream>
using namespace std; 

int main()
{
	Dictionary<Movie> movies(1000); 
	ifstream infile; 
	infile.open("movies.txt");
	int lines = 1;
	

	string line;
	string *c;

	while(getline(infile, line))
	{
		Movie *movie = new Movie; 
		int length = line.length();
		string titles;

		titles = line.substr(0,line.find('\t',0));				//Starts from 0, then gets the tab 																		position

		int start = line.find('\t',0)+1;						//Gets position after the title

		string castList = line.substr(start,length - start);	//Starts after title and gets what 																		remains in line 

		movie->title = titles; 
		movie->cast = castList;
	
		movies.insert(movie);
	}

	infile.close();

	string film;
	cout << "Please select a movie you would like to see the cast for: ";
	getline(cin, film);

	while(film != "q") { 
		Movie *movie = new Movie;
		movie->title = film;
		Movie x = *(movies.get(*movie));
		cout << x << endl;
		cout << "Please select a movie you would like to see the cast for, or enter q to quit: ";
		getline(cin, film);
	}
	return 0; 
}
