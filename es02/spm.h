// Classi Matrix e SparseMatrix
#include <vector>

// Matrice densa
struct Matrix {
  std::vector< std::vector<double> > store;
  int nr;
  int nc;
};

// Elemento di matrice sparsa
struct SparseEntry {
  int r;
  int c;
  double val;
  SparseEntry * next;
};

// Matrice sparsa
struct SparseMatrix {
  SparseEntry * store;
  int nr;
  int nc;
  int nnz;
};


// Creazione di matrice densa a partire da vettore di valori
Matrix matrix(const std::vector<double> & v, const int nr, const int nc);

// Creazione matrice sparsa a partire da matrice densa
SparseMatrix sparse(const Matrix & m);

// Creazione matrice densa a partire da matrice sparsa
Matrix full(const SparseMatrix & s);

// Assegnazione di elemento di matrice sparsa
void  setentry(SparseMatrix & s, const double val,
    const int r, const int c);

// Lettura di elemento di matrice sparsa
double getentry(const SparseMatrix & s, const int r, const int c);

// Somma di matrici sparse
SparseMatrix add(const SparseMatrix & a, const SparseMatrix & b);
