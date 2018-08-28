#ifndef LINKED_H
#define LINKED_H
<<<<<<< HEAD
#include <iostream>
=======

#include <iostream>

>>>>>>> 20e357ef775bae9fa094251060f75697853d8f5f
#include <string>
using namespace std;

struct Word {
	string parola;
};

struct Cell {
	Word * data;
	Cell * next;
};

void printWord(const Word * w);
void insertData(Word * w, string parola);
Word * newWord(const string parola);
Cell * addCellOnHead(Cell * head, Cell * newcell);
<<<<<<< HEAD
void printCell(Cell * c); //da implementare
Cell * newStartingCell(Word * w);
Cell * newCell(Word * w);
=======
void printCell(Cell * c);
Cell * newCell(Word * w);
Cell * deleteCell(Cell * c);
>>>>>>> 20e357ef775bae9fa094251060f75697853d8f5f

#endif
