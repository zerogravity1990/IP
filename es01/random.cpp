#include "random.h"

int random_f(int start, int end)
{//generate random int between given values
	static bool first = true;
	if (first) 
	{	srand( time(NULL) ); //seeding for the first time only!
		first = false;
	}
	int j = rand() % (end-start+1)+start;
	return j;
}
