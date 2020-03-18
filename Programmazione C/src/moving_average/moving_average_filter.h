#ifndef __MOVING_AVERAGE_FILTER_H
#define __MOVING_AVERAGE_FILTER_H

struct maf{
	int size;
	int total;
	float avg;
	int idx;
	int* elements;
};

struct maf moving_average_filter_create(int* elements, const int size);
void moving_average_filter_update(struct maf* filter_struct, const int data);

#endif