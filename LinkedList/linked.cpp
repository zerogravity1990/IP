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
	Word * w = new Word;
	w->parola = parola;
	return w;
}

Cell * newCell(Word * w)
{
	Cell * c = new Cell;
	c->data = w;
	c->next = nullptr;
	return c;
}


Cell * addCellOnHead(Cell * head, Cell * newcell)
{
	newcell->next = head;
	return newcell;
}


void printCell(Cell * c)
{
	if (c == nullptr)
		return;
	Cell * cnext = NULL;
	printWord(c->data);
	cnext = c->next;
	while (cnext != nullptr)
	{
		printWord(cnext->data);
		cnext = cnext->next;
	}
}


Cell * deleteCell(Cell * c)
{
	Cell * next = nullptr;
	if (c == nullptr)
		return nullptr;
	delete c->data;
	next = c->next;
	delete c;
	return next;
}
