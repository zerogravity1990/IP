#ifndef LINKED_H
#define LINKED_H
#include <iostream>
#include <string>
using namespace std;

struct Word {
	string parola;
};

struct Cell {
	struct Word data;
	Cell * next;
	Cell * previous;
};

void printWord(const Word * w);
void insertData(Word * w, string parola);
Word * newWord(const string parola);

#endif
