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
	m.store.resize(nr);
	for(int r=0; r<nr; r++)
		m.store[r].resize(nc);
	for(int r=0; r<nr; r++){
		for(int c=0; c<nc; c++){
			if(c+r*nc < v.size())
				m.store[r][c] = v[c+r*nc];
			else
				m.store[r][c] = 0.0;}}
	return m;
}


// Verifica che un numero sia zero
bool iszero(double val)
// nel calcolo numerico conviene considerare zero un numero sufficientemente piccolo:
// definiamo una tolleranza arbitraria
{
  static const double tolerance = 1e-12;
  return ((val >= 0.0) && (val < tolerance)) || ((val <= 0.0) && (val > -tolerance));
}

//newentry per matrice sparsa
SparseEntry * newentry(double val, int r, int c)
{
	SparseEntry * temp_entry = new SparseEntry;
	temp_entry->r = r;
	temp_entry->c = c;
	temp_entry->val = val;
	temp_entry->next = nullptr;
	return temp_entry;
}

//aggiunge una entry alla lista linkata della sparseMatrix
SparseEntry * add(SparseEntry * matrix, SparseEntry * new_entry)
{
	new_entry->next = matrix;
	return new_entry;
}

//rimuove un elemento in una sparseMatrix
void remove(SparseMatrix * matrix, int r, int c)
{
	int counter = 1, size;
	SparseEntry * prev;
	SparseEntry * current = matrix->store;

	if (current == nullptr) // nessun elemento
		return;

	if ((current->r == r) && (current->c == c)) { // un solo elemento
		
		matrix->store = current->next;
		delete current;
		return;
	}

	size = matrix->nr * matrix->nc;

	while ((nullptr != current->next) && (counter <= size)) {
		prev = current;
		current = current->next;
		if ((current->r == r) && (current->c == c)) {
			prev->next = current->next;
			delete current;
			break;
		}
		counter++;
	}
	return;
}


// Creazione matrice sparsa a partire da matrice densa


//SparseMatrix sparse(const Matrix & m) //perchè per indirizzo e non un puntatore? perchè qua usa la struttura invece che i puntatori?
SparseMatrix sparse(const Matrix m)
// input:
// - Una Matrix m
// output:
// - Un valore di tipo SparseMatrix contenente gli elementi di m in una lista
{	
	SparseMatrix * sparse_matrix = nullptr;
	Matrix * dense_matrix = m;
	//implementare controllo su congruenza righe e colonne
	if (dense_matrix == nullptr)
		return sparse_matrix;
	for (int j = 0; j < dense_matrix->nc; j++)
	{
		sparse_matrix->nc = sparse_matrix->nc + 1;
		for (int i = 0; i < dense_matrix->nr; i++)
		{
			if (iszero(dense_matrix->store[i]))
			{	
				sparse_matrix->nnz = sparse_matrix->nnz + 1;
			}
			else if (sparse_matrix == nullptr)
			{
				sparse_matrix = newEntry(dense_matrix->store[i], dense_matrix->r, dense_matrix->c);
			}
			else
			{
				sparse_matrix = add(sparse_matrix, newEntry(dense_matrix->store[i], dense_matrix->r, dense_matrix->c));
			}
			sparse_matrix->nr = sparse_matrix->nr + 1;
		}
	}
	return sparse_matrix;
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
