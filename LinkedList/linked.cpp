#include "linked.h"

void printWord(const Word * w)
{
	cout << w->parola << endl;
}


void insertData(Word * w, string parola)
{
	w->parola = parola;
}


Word * newWord(const string parola)
{
	Word * w = new Word();
	w->parola = parola;
	return w;
}


Cell * newStartingCell(Word * w)
{
	Cell * c = new Cell();
	c->data = w;
	c->next = nullptr;
	c->previous = nullptr;
}
