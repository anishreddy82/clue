/****************************************************************
  * Author: Group 5
  * Date: 05-01-20
  * Description: implementation file for Notebook class
****************************************************************/

#include "Notebook.hpp"

void Notebook::addEntry(string str) {
	notes.push_back(str);
}

void Notebook::display() {
	for (int i = 0; i < notes.size(); i++)
		cout << "Note " << (i + 1) << ": " << notes.at(i) << endl;
}

void Notebook::eraseEntry(int idx) {
	notes.erase(notes.begin() + (idx - 1));
}

void Notebook::clear() {
	notes.clear();
}
