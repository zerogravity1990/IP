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
<<<<<<< HEAD
	Word * w = new Word();
=======
	Word * w = new Word;
>>>>>>> 20e357ef775bae9fa094251060f75697853d8f5f
	w->parola = parola;
	return w;
}

<<<<<<< HEAD
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
=======
Cell * newCell(Word * w)
{
	Cell * c = new Cell;
	c->data = w;
	c->next = nullptr;
>>>>>>> 20e357ef775bae9fa094251060f75697853d8f5f
	return c;
}


Cell * addCellOnHead(Cell * head, Cell * newcell)
{
	newcell->next = head;
	return newcell;
}

<<<<<<< HEAD
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
		
		
=======

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
>>>>>>> 20e357ef775bae9fa094251060f75697853d8f5f
