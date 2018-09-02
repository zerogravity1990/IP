#include "random.h"

int random_number(int start, int end)
{//generate random int between given values
	static bool first = true;
	if (first) 
	{	srand( time(NULL) ); //seeding for the first time only!
		first = false;
	}
	int j = rand() % (end-start+1)+start;
	return j;
}

int * generateRandomArray(int size)
{
	int * pointer = new int[size];
	for (int i = 0; i < size; i++) {
		pointer[i] = random_number(0, 100);
	}
	return pointer;

}
