#include "spm.h"

// Creazione di matrice densa a partire da vettore di valori
Matrix matrix(const std::vector<double> & v, const int nr, const int nc)
// input:
// - Un vettore di valori numerici
// - Un intero, numero righe
// - Un intero, numero colonne
// output:
// - Un valore di tipo Matrix con nr righe, nc colonne, i cui elementi contengono,
//    in ordine per righe, i valori contenuti in v.
// Se la lunghezza di v eccede il numero di elementi, i valori in eccesso 
// non vengono utilizzati
// Se la lunghezza di v e' inferiore al numero di elementi, i valori mancanti 
// sono posti a zero
{
  // definire una Matrix m
  // porre le sue dimensioni (elementi nr e nc della struct) pari
  //    rispettivamente a nr e nc
  // ridimensionare il vettore m.store alla dimensione nr;
  // iterare r da 0 a nr (escluso)
  //   ridimensionare l'elemento r-esimo di m.store alla dimensione nc;
  // iterare r da 0 a nr (escluso)
  //   iterare c da 0 a nc (escluso)
  //       se l'elemento numero c + r*nc esiste nel vettore v,
  //          assegnare il suo valore all'elemento di m alla riga r, colonna c
  //       altrmenti
  //          porre a zero l'elemento di m alla riga r, colonna c
  //restituire m;

	Matrix m;

	m.nr = nr;
	m.nc = nc;
	m.store.resize(nr); //!!! resize del vector "riga".

	//!!! reasize di ogni vector "colonna":
	for (int r = 0; r < nr; r++) { //!!! spazio tra for e tonda. Spazio tra graffa e tonda.
		m.store[r].resize(nc);//!!! vector "colonna" puntato dal r-esimo elemento del vector "riga".
	}

	for (int r = 0; r < nr; r++) {
		for (int c = 0; c < nc; c++) {
			if ((c + r * nc) < v.size()) {//!!! espressione tra ().
				//!!! (c + r * nc) e' indice nel vettore 1D corrispondente a [r][c] della matrice 2D.
				m.store[r][c] = v[c + r * nc];
			} else { //!!! graffa per leggibilita' e sicurezza
				m.store[r][c] = 0.0;
			}
		} //!!! graffa allineata al for, if, etc, corrispondente.
	}
	
	return m;
}

// Verifica che un numero sia zero
bool iszero(double val)
// nel calcolo numerico conviene considerare zero un numero sufficientemente piccolo:
// definiamo una tolleranza arbitraria
{
	static const double tolerance = 1e-12;//!!! static per allocare la variabile solo la prima volta che la funzione viene chiamata.
					      //!!! const per evitare che la variabile sia modificata dopo la sua definizione e inizializzazione.
	return ((val >= 0.0) && (val < tolerance)) || ((val <= 0.0) && (val > -tolerance));
}

//newentry per matrice sparsa
SparseEntry * newentry(double val, int r, int c)
{
	SparseEntry * temp_entry = new SparseEntry; //!!! Necessario allocarla dinamente perche' deve persistere anche dopo che la funzione esce.
	temp_entry->r = r;
	temp_entry->c = c;
	temp_entry->val = val;
	temp_entry->next = nullptr;
	return temp_entry;
}

//aggiunge una entry alla lista linkata della sparseMatrix
//!!! Mi sembra che matrix dovrebbe chiamarsi first_entry
SparseEntry * add(SparseEntry * matrix, SparseEntry * new_entry)
{
	new_entry->next = matrix;
	return new_entry;
}

//rimuove un elemento in una sparseMatrix

int matrixDim(SparseMatrix * matrix)
{
	dim = (matrix->nr * matrix->nc) - matrix->nnz;
	return dim;
}
//!!! "rimuove un elemento DA una sparseMatrix"
void remove(SparseMatrix * matrix, int r, int c)
{
	SparseEntry * current = matrix->store;
	SparseEntry * next = nullptr;
	if (nullptr == current)
		return;
	for (int i = 0; i < matrixDim(matrix); i++) {
		if (nullptr == current)
			return;
		if ((current->nr == r) && (current->nc == c)) {
			next = current->next;
			delete current;
			current = next;
			next = nullptr;
		}
	}
}

// Creazione matrice sparsa a partire da matrice densa


SparseMatrix sparse(const Matrix & m)
// input:
// - Una Matrix m
// output:
// - Un valore di tipo SparseMatrix contenente gli elementi di m in una lista
{	
	SparseEntry * entry, * head = nullptr;
	SparseMatrix s; // la inizializzo a zero
	s.store = head;
	s.nr = m.nr;
	s.nc = m.nc;
	s.nnz = m.nr * m.nc;
	
	for (int r = 0; r < m.store.size(); r++) {//itero per ogni elemento della matrice
		for (int c = 0; c < m.store[r].size(); c++) {// da verificare l'iterazione
			if (m.store[r][c] != 0) { // se il valore non è zero, creo la entry e popolo la sparse matrix
				entry = newentry(m.store[r][c], r, c);
				head = add(head, entry);
				s.nnz--;
			}
		}
	}
	return s;
}

// Creazione matrice densa a partire da matrice sparsa
Matrix full(const SparseMatrix & s)
// input:
// - Una SparseMatrix s
// output:
// - Un valore di tipo Matrix contenente gli elementi di s
{
  throw "not yet implemented";
}

// Assegnazione di elemento di matrice sparsa
void setentry(SparseMatrix & s, const double val,
    const int r, const int c)
// input:
// - Una SparseMatrix s
// - Un double val, da assegnare a un elemento della matrice
// - Due interi, coordinate di riga e di colonna a cui scrivere
// Modifica la matrice s aggiungendo l'elemento al suo store
// Elimina un elemento se questo viene posto a zero (cioè se val == 0)
{
  throw "not yet implemented";
}

// Lettura di elemento di matrice sparsa
double getentry(const SparseMatrix & s, const int r, const int c)
// input:
// - Una SparseMatrix s
// - Due interi, coordinate di riga e di colonna da cui leggere
// output:
// - Il valore alle coordinate indicate; se nella matrice non c'è l'elemento richiesto,
// significa che è zero e getentry restituisce zero
{
  throw "not yet implemented";
}

// Somma di matrici sparse
SparseMatrix add(const SparseMatrix & a, const SparseMatrix & b)
// input:
// - Due SparseMatrix a e b
// output:
// - Un valore di tipo SparseMatrix contenente la somma delle due matrici a + b

{
  throw "not yet implemented";
}

