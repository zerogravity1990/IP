#include "spm.h"
#include<iostream>
using namespace std;

vector<double> v = {2.7,0.0,54.5,0.0,0.0,0.0,8.5,4.7,6.4,416.7,0.0,0.0,0.0,0.0,8.4,7.6,0.0,7.6};
Matrix m;
SparseMatrix s; 
void printMatrix(const Matrix m);
void printAllSparseEntry(const SparseEntry * s);
void printAllSparseEntry_v2(const SparseEntry * s, int nnz);


int main()
{
	/*SparseEntry * entry1;
	entry1->r = 1;
	entry1->c = 1;
	entry1->val = 0.0;
	entry1->next = nullptr;

	SparseEntry * entry2;
	entry2->r = 1;
	entry2->c = 2;
	entry2->val = 1.5;
	entry2->next = entry1;*/

	m = matrix(v, 2, 6);
	printMatrix(m);
	s = sparse(m);
	//printAllSparseEntry(s.store);
	printAllSparseEntry_v2(s.store, s.nnz);	
}

void printMatrix(const Matrix m)
{
	for (int r = 0; r < m.nr; r++) {//itero per ogni elemento della matrice
		for (int c = 0; c < m.nc; c++) {
			cout << m.store[r][c] << "\t";
		}
		cout << endl;
	}
}

void printAllSparseEntry(const SparseEntry * s)
{
	while(s->next != nullptr){
		cout << "Indice riga: " << s->r << "\t" << "Indice col: " << s->c << "\t" << "Val: " << s->val;
		cout << endl;
		s = s->next;
	}
	cout << "Indice riga: " << s->r << "\t" << "Indice col: " << s->c << "\t" << "Val: " << s->val;
	cout << endl;
}

void printAllSparseEntry_v2(const SparseEntry * s, int nnz)
{
	for (int i = 0; i < nnz; i++){
		cout << "Indice riga: " << s->r << "\t" << "Indice col: " << s->c << "\t" << "Val: " << s->val;
		cout << endl;
		s = s->next;
	}
}


/*
void printAllSparseEntry(const SparseEntry * s)
{
	if (nullptr == s)
		cout << "Puntatore nullo" << endl;
	do {
		cout << "Riga: " << s->r << "\t" << "Col: " << s->c << "\t" << "Val:" << s->val;
		cout << endl;
		s = s->next;
	} while (nullptr != s->next);
}*/

