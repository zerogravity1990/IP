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
	c->data = w;  //come faccio a assegnare la struttura Word a questo field???
	c->next = nullptr;
	return c;
}


Cell * newCell(Word * w)
{
	Cell * c = new Cell();
	c->data = w;
	return c;
}


Cell * addCellOnHead(Cell * head, Cell * newcell)
{
	newcell->next = head;
	return newcell;
}

void printCell(Cell * c)
{
	//throw "da fare";
	while(c->next != nullptr)
	{
		printWord(c->data);
		c = c->next;
	}

	 /*

	Cell * temp = new Cell();
	temp = c;
	while(temp->next != nullptr) //non riesco a iterare la lista
	{
		Word * pw = new Word();
		pw = temp->data;
		printWord(pw);
		temp = temp->next;
	} */
}
		
		
