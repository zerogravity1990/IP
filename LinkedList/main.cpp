#include "linked.h"

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

}
