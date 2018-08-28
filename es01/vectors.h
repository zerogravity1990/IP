#ifndef vectors_H
#define vectors_H

#include <vector>
#include <iostream>

struct Times {
	int hour;
	int minutes;
	int sec;
};

enum Parameters{TEMP, PRESS, HUM};

struct Measurement {
	Parameters meas_parameter;
	struct Times meas_time;
	float meas_value;
};

std::vector<int> generate_v(int size, int val1, int val2);
void print_vector(const std::vector<int>& vect);
void SortVector(std::vector<int>& vect);


Times generate_time(int hour, int minute, int sec);
void print_Times(const Times* t);
void print_Times(const Times t);
void print_array_of_struct(const Times* p, int size);

Times* generate_Times_array(int dim);

int compareTimes(Times t1, Times t2);
void SortByTimes(Times* array, int size);

#endif


