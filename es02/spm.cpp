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
  for (int r = 0; r<nr; r++) m.store[r].resize(nc);
  for (int r = 0; r<nr; r++) {
    for (int c = 0; c<nc; c++) {
      if (c + r*nc<v.size()) m.store[r][c] = v[c + r*nc];
      else m.store[r][c] = 0.0;
    }
  }
  return m;
}

// Verifica che un numero sia zero
bool iszero(double val)
// nel calcolo numerico conviene considerare zero un numero sufficientemente piccolo:
// definiamo una tolleranza arbitraria
{
  static const double tolerance = 1e-12;
  return val>=0 && val<tolerance || val<=0 && val>-tolerance;
}

SparseEntry * add(SparseEntry * store, SparseEntry * entry)
{
  entry->next = store;
  return entry;
}

SparseEntry * remove(SparseEntry * store, int r, int c)
{
  if(store == nullptr) return store;
  if(store->r==r && store->c==c) {
    SparseEntry * updatedstore=store->next;
    delete store;
    return updatedstore;
  }
  store->next=remove(store->next, r, c);
  return store;
}

SparseEntry *newentry(double val, int r, int c)
{
  SparseEntry * tmpentry = new SparseEntry;
  tmpentry->r = r;
  tmpentry->c = c;
  tmpentry->val = val;
  tmpentry->next = nullptr;
  return tmpentry;
}

// Creazione matrice sparsa a partire da matrice densa
SparseMatrix sparse(const Matrix & m)
// input:
// - Una Matrix m
// output:
// - Un valore di tipo SparseMatrix contenente gli elementi di m in una lista
{
  SparseMatrix s;
  s.nnz = 0;
  s.store = nullptr;
  s.nr = m.nr;
  s.nc = m.nc;
  for (int r = 0; r<m.nr; r++) {
    for (int c = 0; c<m.nc; c++) {
      if (m.store[r][c] != 0.0) {
        s.nnz ++ ;
        s.store = add(s.store, newentry(m.store[r][c],r,c));
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
  std::vector<double> v;
  for (int r = 0; r<s.nr; r++)
    for (int c = 0; c<s.nc; c++)
      v.push_back(getentry(s,r,c));
  return matrix(v,s.nr,s.nc);
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
  if(r<0||c<0||r>=s.nr||c>=s.nc)throw "my_out_of_range";
  SparseEntry * cursor = s.store;
  if(iszero(val)) {
    while (cursor!=nullptr && (cursor->c != c || cursor->r != r)) cursor = cursor->next;
    if (cursor == nullptr) return;
    s.store = remove(s.store, r,c);
    s.nnz -- ;
  }
  else {
    while (cursor!=nullptr && (cursor->c != c || cursor->r != r)) cursor = cursor->next;
    if (cursor == nullptr) {
      s.nnz ++ ;
      s.store = add(s.store, newentry(val, r,c));
    }
    else cursor->val = val;
  }
  return;
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
  if(r<0||c<0||r>=s.nr||c>=s.nc)throw "my_out_of_range";
  SparseEntry * cursor = s.store;
  while (cursor!=nullptr && (cursor->c != c || cursor->r != r))
      cursor = cursor->next;
  if (cursor == nullptr) return 0.0;
  return cursor->val;
}

// Somma di matrici sparse
SparseMatrix add(const SparseMatrix & a, const SparseMatrix & b)
// input:
// - Due SparseMatrix a e b
// output:
// - Un valore di tipo SparseMatrix contenente la somma delle due matrici a + b
{
  if(a.nr!=b.nr || a.nc!=b.nc) throw "my_size_mismatch";
  // Creo una SparseMatrix e inizializzo tutti i suoi elementi
  SparseMatrix result;
  result.nr=a.nr;
  result.nc=a.nc;
  result.nnz=0;
  result.store=nullptr;

  // Alternativa: creo una SparseMatrix e la inizializzo a partire da una full creata da un vettore
  //SparseMatrix result=sparse(matrix(std::vector<double>(0),a.nr,a.nc));;
  
  for (int r = 0; r<a.nr; r++) 
    for (int c = 0; c<a.nc; c++)
      setentry(result, getentry(a,r,c) + getentry(b,r,c), r, c);
  return result;
}
