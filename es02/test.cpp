#include <iostream>
#include <stdexcept>
#include "spm.h"

void print(Matrix m)
{
  for (int r=0; r<m.nr; r++) {
    for (int c=0; c<m.nc; c++) std::cout<<m.store[r][c]<<' ';
    std::cout<<std::endl;
  }
}

void print(SparseMatrix s)
{
  for (int r=0; r<s.nr; r++) {
    for (int c=0; c<s.nc; c++) std::cout<<getentry(s,r,c)<<' ';
    std::cout<<std::endl;
  }
}


int main()
{
  try {
    std::cout<<"\n-----Test matrix con dati in eccesso\n";
    std::vector<double> v(30);
    for(int i=0;i<v.size();i++) v[i]=(int)(10*(i+1));
    Matrix m = matrix(v,4,6);
    std::cout<<"Dim:\n"<<m.nr<<", "<<m.nc<<'\n';
    std::cout<<"* Deve essere:\n4, 6\n";
    std::cout<<"Contenuto:\n"; print(m);
    std::cout<<"* Deve essere:\n";
    std::cout<<"10 20 30 40 50 60\n";
    std::cout<<"70 80 90 100 110 120\n";
    std::cout<<"130 140 150 160 170 180\n";
    std::cout<<"190 200 210 220 230 240\n";
  }
  catch(...) {
    std::cout<<"Eccezione\n";
  }

  try {
    std::cout<<"\n-----Test matrix con dati mancanti\n";
    std::vector<double> v(10);
    for(int i=0;i<v.size();i++) v[i]=(int)(10*(i+1));
    Matrix m = matrix(v,4,6);
    std::cout<<"Nuovo contenuto:\n"; print(m);
    std::cout<<"* Deve essere:\n";
    std::cout<<"10 20 30 40 50 60\n";
    std::cout<<"70 80 90 100 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
  }
  catch(...) {
    std::cout<<"Eccezione\n";
  }

  try {
    std::cout<<"\n-----Test sparse con contenuto vuoto\n";
    SparseMatrix s = sparse(matrix(std::vector<double>(0),4,6));
    std::cout<<"Dim:\nnr = "<<s.nr<<"   nc = "<<s.nc<<"   nnz = "<<s.nnz<<std::endl; 
    std::cout<<"* Deve essere:\nnr = 4   nc = 6   nnz = 0\n";
    std::cout<<"Contenuto:\n"; print(s);
    std::cout<<"* Deve essere:\n";
    std::cout<<"0 0 0 0 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
  }
  catch(...) {
    std::cout<<"Eccezione\n";
  }

  try {
    std::cout<<"\n-----Test setentry\n";
    SparseMatrix s = sparse(matrix(std::vector<double>(0),4,6));
    setentry(s,100,3,3);
    std::cout<<"Dim:\nnr = "<<s.nr<<"   nc = "<<s.nc<<"   nnz = "<<s.nnz<<std::endl; 
    std::cout<<"* Deve essere:\nnr = 4   nc = 6   nnz = 1\n";
    std::cout<<"Contenuto:\n"; print(s);
    std::cout<<"* Deve essere:\n";
    std::cout<<"0 0 0 0 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
    std::cout<<"0 0 0 100 0 0\n";
  }
  catch(...) {
    std::cout<<"Eccezione\n";
  }

  try {
    std::cout<<"\n-----Test sparse\n";
    std::vector<double> v(10);
    for(int i=0;i<v.size();i++) v[i]=(int)(10*(i+1));
    Matrix m = matrix(v,4,6);
    SparseMatrix s = sparse(m);
    std::cout<<"Dim:\nnr = "<<s.nr<<"   nc = "<<s.nc<<"   nnz = "<<s.nnz<<std::endl; 
    std::cout<<"* Deve essere:\nnr = 4   nc = 6   nnz = 10\n";
    std::cout<<"Contenuto:\n"; print(s);
    std::cout<<"* Deve essere:\n";
    std::cout<<"10 20 30 40 50 60\n";
    std::cout<<"70 80 90 100 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
  }
  catch(...) {
    std::cout<<"Eccezione\n";
  }

  try {
    std::cout<<"\n-----Test assegnazione zeri sparse\n";
    std::vector<double> v(10);
    for(int i=0;i<v.size();i++) v[i]=(int)(10*(i+1));
    SparseMatrix s = sparse(matrix(v,4,6));
    setentry(s,0.0,1,0);
    setentry(s,0.0,0,1);
    setentry(s,0.0,1,1);
    std::cout<<"Dim:\nnr = "<<s.nr<<"   nc = "<<s.nc<<"   nnz = "<<s.nnz<<std::endl; 
    std::cout<<"* Deve essere:\nnr = 4   nc = 6   nnz = 7\n";
    std::cout<<"Contenuto:\n"; print(s);
    std::cout<<"* Deve essere:\n";
    std::cout<<"10 0 30 40 50 60\n";
    std::cout<<"0 0 90 100 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
  }
  catch(...) {
    std::cout<<"Eccezione\n";
  }

  try {
    std::cout<<"\n-----Test full\n";
    std::vector<double> v(10);
    for(int i=0;i<v.size();i++) v[i]=(int)(10*(i+1));
    Matrix m = matrix(v,4,6);
    SparseMatrix s = sparse(m);
    Matrix m2 = full(s);
    std::cout<<"Dim:\n"<<m2.nr<<", "<<m2.nc<<'\n';
    std::cout<<"* Deve essere 4, 6\n";
    if(m.nr!=m2.nr || m.nc!=m2.nc) std::cout<<"Confronto: fallito per dimensioni diverse\n";
    else {
      std::cout<<"Confronto:\n";
      for (int r=0; r<m.nr; r++) {
	for (int c=0; c<m.nc; c++) std::cout<<(m.store[r][c]==m2.store[r][c])<<' ';
	std::cout<<'\n';
      }
      std::cout<<"* Deve essere:\n";
      std::cout<<"1 1 1 1 1 1\n";
      std::cout<<"1 1 1 1 1 1\n";
      std::cout<<"1 1 1 1 1 1\n";
      std::cout<<"1 1 1 1 1 1\n";
    }
  }
  catch(...) {
    std::cout<<"Eccezione\n";
  }

  try {
    std::cout<<"\n-----Test add\n";
    std::vector<double> v(10);
    for(int i=0;i<v.size();i++) v[i]=(int)(10*(i+1));
    SparseMatrix s1 = sparse(matrix(v,4,6));
    setentry(s1,-10,0,0);
    setentry(s1,-20,0,1);
    SparseMatrix s2 = sparse(matrix(v,4,6));
    SparseMatrix ssum = add(s1,s2);
    std::cout<<"Dim:\nnr = "<<ssum.nr<<"   nc = "<<ssum.nc<<"   nnz = "<<ssum.nnz<<std::endl; 
    std::cout<<"* Deve essere:\nnr = 4   nc = 6   nnz = 8\n";
    std::cout<<"Contenuto:\n"; print(ssum);
    std::cout<<"* Deve essere:\n";
    std::cout<<"0 0 60 80 100 120\n";
    std::cout<<"140 160 180 200 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
    std::cout<<"0 0 0 0 0 0\n";
  }
  catch(...) {
    std::cout<<"Eccezione\n";
  }

  try {
    std::cout<<"\n-----Test exception\n";
    std::vector<double> v(10);
    for(int i=0;i<v.size();i++) v[i]=(int)(10*(i+1));
    SparseMatrix s = sparse(matrix(v,4,6));
    getentry(s,100,100);
    std::cout<<"No eccezione, test fallito\n";
  }
  catch (const std::out_of_range& oor) {
    std::cerr << "Eccezione Out of Range: forse sollevata da std::vector?\n";
  }
  catch(...) {
    std::cout<<"Eccezione, test superato\n";
  }
}
