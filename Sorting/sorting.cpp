#include "sorting.h"

//ordina in modo crescente un array tramite selection sort
void selectionSorting(int * array, int dim) {
	for (int i = 0; i < dim; i++) {
		int smallest_index = i;
		for (int cursor = i+1; cursor < dim; cursor++) {
			if (array[cursor] < array[smallest_index]) {
				smallest_index = cursor;
			}
		}
		int temp = array[i];
		array[i] = array[smallest_index];
		array[smallest_index] = temp;
	}
}


//ritorna l'indice della posizione nell'array se il valore viene trovato. Torna -1 se non trova il valore.
int binarySearch(const int array[], int dim, int x) {
	int left_index, right_index, middle_index;
	left_index = 0;
	right_index = dim -1;
	middle_index = (left_index + right_index) / 2;
	
	while ((array[middle_index] != x) && (left_index <= right_index)) {
		if (x > array[middle_index]) {
			left_index = middle_index + 1;
			middle_index = (left_index + right_index) / 2;
		}
		else if (x < array[middle_index]) {
			right_index = middle_index - 1;
			middle_index = (left_index + right_index) / 2;
		}
	}

	if (array[middle_index] == x) {
		return middle_index;
	} else {
		return -1;
	}
}
