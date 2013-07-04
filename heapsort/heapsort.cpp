//============================================================================
// Name        : heapsort.cpp
// Author      : Alex Zhang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void heapify(int *array, unsigned int index, unsigned int heap_size){
	unsigned int l = 2*index + 1;
	unsigned int r = l + 1;

	unsigned int largest = 0;
	if (l <= heap_size-1 && array[l] > array[index])
		largest = l;
	else
		largest = index;

	if (r <= heap_size-1 && array[r] > array[largest])
		largest = r;

	if (largest != index){
		swap(&array[largest], &array[index]);
        heapify(array, largest, heap_size);
	}
}

void build_heap(int *array, unsigned int heap_size){
        int index = (heap_size - 1)/2;
        
        while(index >= 0) heapify(array, index--, heap_size); 
}

int main(void) {
	puts("HeapSort - Intro to algorithms");

	int array[10] = {8, 3, 19, 2, 6, 12, 17, 9, 7, 4};
	build_heap(array, 10);
        puts("Done");
	return EXIT_SUCCESS;
}
