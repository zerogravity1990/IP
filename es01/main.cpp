#include "vectors.h"
using namespace std;

int main()
{
	const int DIMENSION = 10;
	vector<int> v = generate_v(10,0,100);
	cout << "Vettore generato: "; print_vector(v);
	SortVector(v);
	cout << "Vettore ordinato: "; print_vector(v);
	struct Times t = generate_time(12, 40, 55);
	struct Times* pointerT;
	pointerT = &t; 
	print_Times(pointerT);
	print_Times(t);
	struct Times* pt;
	pt = generate_Times_array(DIMENSION);
	print_array_of_struct(pt, DIMENSION);
	
	cout << "*******************************" << endl;

	SortByTimes(pt, DIMENSION);
	print_array_of_struct(pt, DIMENSION);
}
