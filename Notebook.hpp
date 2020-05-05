/****************************************************************
  * Author: Group 5
  * Date: 05-01-20
  * Description: Notebook class which will hold a vector of
  		 player defined strings
****************************************************************/

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::cin;

class Notebook {
	private:
		vector<string> notes;
	public:
		void addEntry(string);
		void display();
		void eraseEntry(int);
		void clear();
};

#endif
