#include "random.h"
#include "vectors.h"
using namespace std;


vector<int> generate_v(int size, int val1, int val2)
{//generate a vector filled with random values
	vector<int> v1;
	for(int i=0; i<size; i++)
	{	v1.push_back(random_f(val1, val2));
	}
	return v1;
}

void print_vector(const vector<int>& vect)
{//print elements of passed vector
	for(int i=0; i<vect.size(); i++)
	{	cout << vect[i] << " ";
	}
	cout << endl;
}

void SortVector(vector<int>& vect)
{//should sort elements of passed vector
	for(int i=0; i<vect.size(); i++)
	{	int smallest_index = i;
		for(int mini=i+1; mini < vect.size(); mini++)
		{	if(vect[mini] < vect[smallest_index])
			{	smallest_index = mini;
			}
		}
		int temp = vect[smallest_index];
		vect[smallest_index] = vect[i];
		vect[i] = temp;
	}
}

Times generate_time(int hour, int minute, int sec)
{//return a Time obj with field compiled
	struct Times t;
	t.hour = hour;
	t.minutes = minute;
	t.sec = sec;
	return t;
}



void print_Times(const Times t)
{//print times field values
	cout << "Time: " << t.hour << ":" << t.minutes << ":" << t.sec << endl;
}

void print_Times(const Times* t)
{//print times field values from pointer
	cout << "Time: " << t->hour << ":" << t->minutes << ":" << t->sec << endl;
}

void print_array_of_struct(const Times* p, int size)
{//print an array of struct from a pointer
	for(int i=0; i<size; i++)
	{
	cout << "Time n." << i+1 << ": " << p[i].hour << ":" << p[i].minutes << ":" << p[i].sec << endl;
	}
}

Times* generate_Times_array(int dim)
{//generate an array of Times
	Times* pointer = new Times[dim];
	for(int i=0; i<dim; i++)
	{
		Times t = generate_time(random_f(0,12), random_f(0,60), random_f(0, 60));
		pointer[i] = t;
	}
	return pointer;
}

int compareTimes(Times t1, Times t2)
{//return an integer resulting from the comparison between times
	if(t1.hour==t2.hour && t1.minutes==t2.minutes && t1.sec==t2.sec)
	{	return 0;
	}
	else if (t1.hour!=t2.hour)
	{	return (t1.hour - t2.hour);
	}
	else if (t1.minutes!=t2.minutes)
	{	return (t1.minutes - t2.minutes);
	}
	else if (t1.sec!=t2.sec)
	{	return (t1.sec - t2.sec);
	}
}

void SortByTimes(Times* array, int size)
{//sort times array
	for(int i=0; i<size; i++)
	{	int small_index = i;
		for(int mini=i+1; mini<size; mini++)
		{	if(compareTimes(array[i], array[mini]) > 0)
				small_index = i;
			else if (compareTimes(array[i], array[mini]) < 0)
				small_index = mini;
		Times temp = array[small_index];
		array[small_index] = array[mini];
		array[mini] = temp;
		}
	}
}
