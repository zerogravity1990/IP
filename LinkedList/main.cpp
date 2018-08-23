#include "linked.h"

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

}
