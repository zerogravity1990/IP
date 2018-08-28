#include "linked.h"

<<<<<<< HEAD
string dizionario[] = {"alessandro", "leonida", "elon", "cesare", "nonna maria"};
string parola = "";
string parola2 = "";
Word * w = new Word(); //differenza tra () si parentesi no???
Cell * c = new Cell; // questi due prima li avevo inizializzati a nullptr e dava errore di runtime "Segmentation fault (core dumped)" perchè?
Cell * head = new Cell;

int main(){

parola = "testWord";
parola2 = "testWord2";

insertData(w, parola);
printWord(w);
c = newStartingCell(w);
Word * w2 = new Word();
insertData(w2, parola2);
Cell * c2 = new Cell();
c2 = newCell(w2);
head = addCellOnHead(c,c2);

cout << head->data->parola << endl;
cout << head->next << endl;
cout << c->next << endl;

printCell(c2);
delete w;
delete c;
=======
Word * w = nullptr;
Cell * c = nullptr;
Cell * c2 = nullptr;
string dizionario[10] = {"ciao1","ciao2","ciao3","ciao4","ciao5","ciao6","ciao7","ciao8","ciao9","ciao10"};


int main(){

	int i = 0;
	w = newWord(dizionario[0]);
	c = newCell(w);

	for (i = 1; i < 10; i++)
	{
		w = newWord(dizionario[i]);
		c2 = newCell(w);

		c = addCellOnHead(c, c2);
	}

	printCell(c);

	for (i = 0; (i < 10) && (c != nullptr); i++)
	{
		c = deleteCell(c);
	}


	return 1;
>>>>>>> 20e357ef775bae9fa094251060f75697853d8f5f

}
