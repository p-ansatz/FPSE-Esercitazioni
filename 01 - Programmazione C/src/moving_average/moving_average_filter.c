#include <stdio.h>
#include "moving_average_filter.h"

struct maf moving_average_filter_create(int* elements, const int size){
	struct maf tmp;
	
	tmp.size = size;
	tmp.elements = elements;
	tmp.total = 0;
	tmp.avg = 0;
	tmp.idx = 0;
	
	return tmp;
}

void moving_average_filter_update(struct maf* filter_struct, const int data){    
	// Remove oldest value
	filter_struct->total -= filter_struct->elements[filter_struct->idx];
	// Add current measure
	filter_struct->total += data;
	// Calculate Average
	filter_struct->avg = (float) filter_struct->total/filter_struct->size;
	// Store current measure
	filter_struct->elements[filter_struct->idx] = data;

	// Increase index
	if(filter_struct->idx < (filter_struct->size - 1))
		filter_struct->idx++;
	else
		filter_struct->idx = 0;
}