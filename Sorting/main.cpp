#include "sorting.h"
#include "random.h"

const int ARRAY_SIZE = 10;
void printArray(int * array, int size);
int num = 9;

int array2[] = {1,2,3,4,5,6,7,8,9,10};

int main() {

	int * pointer = generateRandomArray(ARRAY_SIZE);
	printArray(pointer, ARRAY_SIZE);
	cout << endl;
	selectionSorting(pointer, ARRAY_SIZE);
	printArray(pointer, ARRAY_SIZE);
	cout << endl;

	cout << binarySearch(pointer, ARRAY_SIZE, pointer[6]);
	cout << endl;
}

void printArray(int * array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}
