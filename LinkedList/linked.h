#ifndef LINKED_H
#define LINKED_H
#include <iostream>
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
void printCell(Cell * c); //da implementare
Cell * newStartingCell(Word * w);
Cell * newCell(Word * w);

#endif
